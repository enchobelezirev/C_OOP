#pragma once
#include <vector>
#include <fstream>
#include "MapNode.h"
#include "Pair.h"
#include "HashFunction.h"

using namespace std;

template <typename T>
class KeyValueStore
{
private:
	const char* keysFileName = "data-keys.dat";
	const char* valuesFileName = "data-values.dat";
private:
	HashFunction<T> hashFunction;
	vector<Node<T>> elements;
	void copyOther(const KeyValueStore& other) {
		this->elements = other.elements;
		this->hashFunction = other.hashFunction;
	}

private:
	Node<T> createTemporaryNode(size_t key, int startPosition, int numberOfBytes, int value) {
		Node<T> tempNode;
		tempNode.key = key;
		tempNode.startPosition = startPosition;
		tempNode.numberOfBytes = numberOfBytes;
		tempNode.value = value;
		return tempNode;
	}

	void insertIfNecessary(size_t hashValue, Node<T> n) {
		readKeysFile();
		if (elements.empty())
		{
			n.startPosition = 0;
			elements.push_back(n);
			writeKeysFile();
			writeValuesFile(n.startPosition, n.numberOfBytes, n.value);
		}
		else {
			Node<T>* existingKeyValue = findValue(hashValue)._2;
			if (existingKeyValue == nullptr) {
				Node<T> lastValue = elements[elements.size() - 1];
				n.startPosition = lastValue.numberOfBytes + lastValue.startPosition;
				elements.push_back(n);
				writeKeysFile();
				writeValuesFile(n.startPosition, n.numberOfBytes, n.value);
			}
		}
	}
	Pair<size_t, Node<T>*> findValue(size_t key) {
		for (size_t i = 0; i < elements.size(); i++)
		{
			if (elements[i].key == key)
			{
				return Pair<size_t, Node<T>*>(i, &elements[i]);
			}
		}
		return Pair<size_t, Node<T>*>(-1, nullptr);
	}
	void writeValuesFile(int pStart, int bytestToWrite, T valueToWrite) {
		ofstream file(valuesFileName, ios::binary | ios::app | ios::ate);
		file.seekp(pStart, ios::beg);
		file.write(reinterpret_cast<const char*>(&valueToWrite), bytestToWrite);
		file.close();
	}

	T& readValuesFile(int gStart, int bytesToRead) {
		ifstream file(valuesFileName, ios::in | ios::binary);
		file.seekg(gStart, ios::beg);
		T value;
		file.read(reinterpret_cast<char*>(&value), bytesToRead);
		file.close();
		return value;
	}

	void readKeysFile() {
		elements = vector<Node<T>>();
		ifstream file(keysFileName, ios::in);
		size_t key;
		int startPosition;
		int numberOfBytes;
		while (file >> key >> startPosition >> numberOfBytes)
		{
			Node<T> currNode = createTemporaryNode(key, startPosition, numberOfBytes, 0);
			elements.push_back(currNode);
		}
		file.close();
	}

	void writeKeysFile() {
		ofstream file(keysFileName, ios::out);
		for (size_t i = 0; i < elements.size(); i++)
		{
			Node<T> currNode = elements[i];
			file << currNode.key << " " << currNode.startPosition << " " << currNode.numberOfBytes << '\n';
		}
		file.close();
	}
	
public:
	KeyValueStore() {
		this->hashFunction = HashFunction<T>();
	}

	KeyValueStore& operator=(const KeyValueStore& other)
	{
		if (*this != other)
		{
			copyOther(other);
		}
		return *this;
	}

	KeyValueStore(const KeyValueStore& other) {
		copyOther(other);
	}

	~KeyValueStore() {
	}

	T Store(const T* pBlock, size_t pSize) {
		size_t hashValue = hashFunction.calculateHash(pBlock);
		Node<T> n = createTemporaryNode(hashValue, 0, pSize, *pBlock);
		insertIfNecessary(hashValue, n);
		return n.key;
	}

	T* Load(const size_t pKey) {
		readKeysFile();
		Node<T>* foundElement = findValue(pKey)._2;
		if (!foundElement)
		{
			throw exception("Invalid key!");
		}
		return &readValuesFile(foundElement->startPosition, foundElement->numberOfBytes);
	}

	bool Erase(const size_t pKey) {
		readKeysFile();
		Pair<size_t, Node<T>*> foundPair = findValue(pKey);
		Node<T>* foundNode = foundPair._2;
		if (!foundNode)
		{
			return false;
		}
		elements.erase(elements.begin() + foundPair._1);
		writeKeysFile();
	}
};


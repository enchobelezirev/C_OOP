#pragma once
#include <iostream>
using namespace std;
template <typename T>
class HashFunction
{
private:
	hash<T> hash;
public:
	HashFunction() {
		this->hash = std::hash<T>();
	}
	size_t calculateHash(const T* value) {
		return this->hash(*value);
	}
};

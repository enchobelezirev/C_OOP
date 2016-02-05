#pragma once
template <typename T>
struct Node {
	size_t key;
	T value;
	int startPosition;
	size_t numberOfBytes;
};


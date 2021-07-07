#pragma once
#include "BSTreeNodeHeader.h"
#include "HuffmanNodeHeader.h"

// Heap Class
class Heap
{
private:
	HuffmanNode** data;
	int heapSize;
	int maxSize; // max size of heap
	int allocated; // 1 if heap allocated memory
	/// static for quick caculate:
	static int Left(int node) { return (node * 2) + 1; };
	static int Right(int node) { return (node * 2) + 2; };
	static int Parent(int node) { return (node - 1) / 2; };

public:
	Heap(int max);
	Heap(HuffmanNode* C[], int n); //BuildHeap
	void operator=(const Heap&) = delete;
	Heap(const Heap&) = delete;
	~Heap();

public:
	HuffmanNode* Min() const { return data[0]; }; // return the minimum pair of the heap
	HuffmanNode* DeleteMin();
	void Insert(HuffmanNode* item);
	void FixHeap(int node);
	void Swap(HuffmanNode*& a, HuffmanNode*& b);

};
#include "HeapHeader.h"

Heap::Heap(int max)
{
	data = new HuffmanNode * [max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}

// Build heap
Heap::Heap(HuffmanNode* C[], int n)
{
	heapSize = n;
	maxSize = n;

	data = C;
	allocated = 0;

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}

Heap::~Heap()
{
	if (allocated)
		delete[] data;
	data = nullptr;
}

// Fix the heap after remove the min
void Heap::FixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	// Find minimum among node, left and right:
	if ((left < heapSize) && (data[left]->Frequency() < data[node]->Frequency()))
	{
		min = left;
	}
	else
	{
		min = node;
	}

	if ((right < heapSize) && (data[right]->Frequency() < data[min]->Frequency()))
	{
		min = right;
	}

	if (min != node)
	{
		Swap(data[node], data[min]);
		FixHeap(min);
	}
}

// Swap two nodes
void Heap::Swap(HuffmanNode*& a, HuffmanNode*& b)
{
	HuffmanNode* temp = a;
	a = b;
	b = temp;
}

// Delete the minimum of the heap
HuffmanNode* Heap::DeleteMin()
{
	if (heapSize < 1)
		return nullptr;

	HuffmanNode* min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return(min);
}

// Insert node to the heap
void Heap::Insert(HuffmanNode* item)
{
	if (heapSize == maxSize)
	{
		return;
	}

	int i = heapSize;
	heapSize++;

	while ((i > 0) && data[Parent(i)]->Frequency() > item->Frequency())
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = item;
}
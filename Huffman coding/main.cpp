#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "binarySearchTreeHeader.h"
#include "HuffmanNodeHeader.h"
#include "HeapHeader.h"

/*-------------------------------------------------------------------

User Manual:
1. Insert the name of a text file (include ".txt").
2. The program will calculate and print a Huffman Code and its weight.
3. In case of any error - the program will notify and exit.

-------------------------------------------------------------------*/

using namespace std;

/// Function Decleration:
HuffmanNode* Huffman(HuffmanNode* C[], int n);
HuffmanNode** convertHuffmanNodeArray(BSTree& t, int n);
void recursivePreOrder(HuffmanNode** arr, BSTreeNode* root);
void addToArray(HuffmanNode** arr, BSTreeNode* item);
void readFromTxt(char* str, BSTree& t);
char* getStr();

/// Main:
int main()
{
	BSTree t;
	char* str = getStr();
	int sum = 0;
	int nodes; // How many nodes

	readFromTxt(str, t); // Set binary tree from file

	// Build Huffman code from the tree and print it:
	nodes = t.getNumOfNodes();
	if (nodes > 0)
	{
		HuffmanNode** C = convertHuffmanNodeArray(t, nodes);
		HuffmanNode* node = Huffman(C, nodes);

		cout << endl << "Characters encoding :" << endl;
		str = new char[nodes];
		node->code(str, 0, sum);
		cout << endl << "Encoded file weight: " << sum << " bits" << endl;
		delete[] C;
	}
	else
	{
		cout << "Empty file" << endl;
	}

	delete str;
	return 0;
}

/// Function Implentation:
HuffmanNode* Huffman(HuffmanNode* C[], int n)
{
	Heap Q(C, n); //BuildHeap
	HuffmanNode* node;

	for (int i = 1; i < n; i++)
	{
		node = new HuffmanNode;
		node->SetLeft(Q.DeleteMin());
		node->SetRight(Q.DeleteMin());

		node->SetFrequency(node->getLeft()->Frequency() + node->getRight()->Frequency());

		Q.Insert(node);
	}
	return Q.DeleteMin();
}

// Convert the binary tree to an array of HuffmanNode*
HuffmanNode** convertHuffmanNodeArray(BSTree& t, int n)
{
	HuffmanNode** arr = new HuffmanNode * [n];
	recursivePreOrder(arr, t.getRoot());
	return arr;
}

// Pre order on the tree and insert to array
void recursivePreOrder(HuffmanNode** arr, BSTreeNode* root)
{
	if (root != nullptr)
	{
		addToArray(arr, root);
		if (root->getLeft() != nullptr)
		{
			recursivePreOrder(arr, root->getLeft());
		}

		if (root->getRight() != nullptr)
		{
			recursivePreOrder(arr, root->getRight());
		}
	}
}

// Add node of the tree to the array
void addToArray(HuffmanNode** arr, BSTreeNode* item)
{
	static int index = 0;
	HuffmanNode* temp = new HuffmanNode(item->getValue()->key, item->getValue()->count);
	arr[index] = temp;
	index++;
}

// Read from file into and create a tree on - t
void readFromTxt(char* str, BSTree& t)
{
	ifstream infile;
	infile.open(str);
	char value;
	if (!infile)
	{
		cout << "Invalid Input." << endl;
		exit(1);
	}
	value = infile.get();

	while (!infile.eof())
	{
		if (!infile.good())
		{
			cout << "Error reading file." << endl;
			exit(1);
		}
		t.Insert(value);
		value = infile.get();
	}
	infile.close();
}

// Get name of file from user
char* getStr()
{
	char* str = new char[128];
	cout << "Enter the name of the file :" << endl;
	cin.getline(str, 128);
	return str;
}

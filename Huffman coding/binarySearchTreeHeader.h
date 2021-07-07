#pragma once
#include "BSTreeNodeHeader.h"

// Binary Search Tree Class
class BSTree
{
private:
	BSTreeNode* root;
	int numOfNodes;

public:
	BSTree() : root(nullptr) { numOfNodes = 0; };
	void operator=(const BSTree&) = delete;
	BSTree(const BSTree&) = delete;
	~BSTree();

public:
	int getNumOfNodes() { return numOfNodes; };
	BSTreeNode* getRoot() { return root; };
	BSTreeNode* find(char key) const;
	void MakeEmpty();
	bool IsEmpty();
	void Insert(char key);
	void Delete(char key);
	void printTree() const;
	BSTreeNode* findParent(BSTreeNode* v) const;
};

//#include <iostream>
//using namespace std;
#include "binarySearchTreeHeader.h"

BSTree::~BSTree()
{
	if (root != nullptr)
		MakeEmpty();
}

// Find node by key
BSTreeNode* BSTree::find(char key) const
{
	BSTreeNode* temp = root;
	while (temp != nullptr)
	{
		if (key == (temp->getValue())->key)
			return temp;
		else if (key < (temp->getValue())->key)
			temp = temp->getLeft();
		else
			temp = temp->getRight();

	}
	return nullptr;
}

// Insert new node on the tree
void BSTree::Insert(char key)
{
	BSTreeNode* temp = find(key);
	BSTreeNode* parent = nullptr;
	BSTreeNode* newNode;

	if (temp != nullptr)
	{
		temp->setValue();
		return;
	}

	temp = root;

	while (temp != nullptr)
	{
		parent = temp;
		if (key < (temp->getValue()->key))
			temp = temp->getLeft();
		else
			temp = temp->getRight();
	}

	Pair item;
	item.count = 1;
	item.key = key;

	newNode = new BSTreeNode(item, nullptr, nullptr);

	if (parent == nullptr) // if newNode is the root
	{
		root = newNode;
	}
	else if (key < (parent->getValue()->key))
		parent->setLeft(newNode);
	else
		parent->setRight(newNode);

	numOfNodes++;
}

// Return true id the tree is empty
bool BSTree::IsEmpty()
{
	if (root != nullptr)
		return false;
	return true;
}

// Empty tree
void BSTree::MakeEmpty()
{
	delete root;
	root = nullptr;
}

// Delete node by key
void BSTree::Delete(char key)
{
	BSTreeNode* toDelete = find(key);
	BSTreeNode* parent = nullptr;
	BSTreeNode* temp = nullptr;
	BSTreeNode* max;

	// If the key doesnt exist:
	if (toDelete == nullptr)
	{
		return;
	}
	// If the cell have 0 childrens
	if (toDelete->numOfChildren() == 0)
	{
		if (toDelete == root)
		{
			root = nullptr;
		}
		else
		{
			parent = findParent(toDelete);
			if (parent->getLeft() == toDelete)
			{
				parent->setLeft(nullptr);
			}
			else
			{
				parent->setRight(nullptr);
			}
			toDelete->setLeft(nullptr);
			toDelete->setRight(nullptr);
		}
		delete toDelete;
	}
	// If the cell have 1 child
	else if (toDelete->numOfChildren() == 1)
	{
		if (toDelete == root)
		{
			if (toDelete->getLeft() == nullptr)
			{
				root = toDelete->getRight();

			}
			else
			{
				root = toDelete->getLeft();
			}
		}
		else
		{
			parent = findParent(toDelete);
			if (toDelete->getLeft() == nullptr)
			{
				temp = toDelete->getRight();
			}
			else
			{
				temp = toDelete->getLeft();
			}
			if (parent->getLeft() == toDelete)
			{
				parent->setLeft(temp);
			}
			else
			{
				parent->setRight(temp);
			}
		}
		toDelete->setLeft(nullptr);
		toDelete->setRight(nullptr);
		delete toDelete;
	}
	// If the cell have 2 childrens
	else if (toDelete->numOfChildren() == 2)
	{
		max = toDelete->getLeft()->Max();
		toDelete->setValue(max->getValue());

		temp = toDelete->getLeft();
		if (temp->numOfChildren() == 0)
		{
			parent = toDelete;
			parent->setLeft(nullptr);
		}

		else if (temp->getRight() != nullptr)
		{
			while (temp->getRight()->getRight() != nullptr)
			{
				temp = temp->getRight();
			}
			parent = temp;
			parent->setRight(max->getLeft());
		}

		max->setLeft(nullptr);
		max->setRight(nullptr);

		delete max;
	}

	numOfNodes--;
}

// Print tree
void BSTree::printTree() const
{
	if (root != nullptr)
		root->Inorder();
}

// Find the parent of the node
BSTreeNode* BSTree::findParent(BSTreeNode* v) const
{
	BSTreeNode* parent = nullptr;
	BSTreeNode* temp = root;
	Pair* val = v->getValue();
	while (temp != nullptr)
	{
		if (temp->getRight() == v)
		{
			parent = temp;
			temp = nullptr;
		}
		else if (temp->getLeft() == v)
		{
			parent = temp;
			temp = nullptr;
		}
		else if (val->key < (temp->getValue()->key))
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}
	return parent;
}
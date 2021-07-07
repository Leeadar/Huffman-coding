#include "BSTreeNodeHeader.h"
#include <iostream>
using namespace std;

BSTreeNode::BSTreeNode()
{
	value = nullptr;
	left = nullptr;
	right = nullptr;

}

BSTreeNode::BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right)
{
	Pair* newItem = new Pair;
	newItem->key = item.key;
	newItem->count = item.count;

	value = newItem;

	left = left;
	right = right;
}

BSTreeNode::~BSTreeNode()
{
	if (left != nullptr)
	{
		delete left;
		left = nullptr;
	}
	if (right != nullptr)
	{
		delete right;
		right = nullptr;
	}
	delete value;
	makeEmpty();
}

// Empty tree
void BSTreeNode::makeEmpty()
{
	value = nullptr;
	left = nullptr;
	right = nullptr;
}

// Print tree inorder
void BSTreeNode::Inorder() const
{
	if (value != nullptr)
	{
		if (this->getLeft())
		{
			left->Inorder();
		}
		// special chars:
		if (value->key == '\n')
		{
			cout << "Key: " << "\\n" << " Count = " << value->count << endl;
		}
		else if (value->key == '\t')
		{
			cout << "Key: " << "\\t" << " Count = " << value->count << endl;
		}
		else {
			cout << "Key: " << value->key << " Count = " << value->count << endl;
		}

		if (this->getRight())
		{
			right->Inorder();
		}
	}
}

// Print tree preorder
void BSTreeNode::Preorder() const
{
	if (value != nullptr)
	{
		if (value->key == '\n')
		{
			cout << "Key: " << "\\n" << " Count = " << value->count << endl;
		}
		else if (value->key == '\t')
		{
			cout << "Key: " << "\\t" << " Count = " << value->count << endl;
		}
		else {
			cout << "Key: " << value->key << " Count = " << value->count << endl;
		}

		if (this->getLeft() != nullptr)
		{
			left->Inorder();
		}
		if (this->getRight() != nullptr)
		{
			right->Inorder();
		}
	}
}

// Print tree postorder
void BSTreeNode::PostOrder() const
{
	if (value != nullptr)
	{
		if (this->getLeft() != nullptr)
		{
			left->Inorder();
		}

		if (this->getRight() != nullptr)
		{
			right->Inorder();
		}
		if (value->key == '\n')
		{
			cout << "Key: " << "\\n" << " Count = " << value->count << endl;
		}
		else if (value->key == '\t')
		{
			cout << "Key: " << "\\t" << " Count = " << value->count << endl;
		}
		else {
			cout << "Key: " << value->key << " Count = " << value->count << endl;
		}

	}
}

// Return how many direct childrens node have (0/1/2)
int BSTreeNode::numOfChildren() const
{
	int count = 0;
	if (left != nullptr)
		count++;
	if (right != nullptr)
		count++;

	return count;
}

// Find the max child of the node
BSTreeNode* BSTreeNode::Max()
{
	if (this->getRight() != nullptr)
	{
		return right->Max();
	}
	else
	{
		return this;
	}
}

// Sets the value of a node
void BSTreeNode::setValue(Pair* val)
{
	value->count = val->count;
	value->key = val->key;
}

#pragma once

// Struct of ley & counter
typedef struct
{
	char key;
	int count;
}Pair;

// Binary Search Tree Node Class
class BSTreeNode
{
private:
	Pair* value;
	BSTreeNode* left, * right;

public:
	BSTreeNode();
	BSTreeNode(Pair item, BSTreeNode* left, BSTreeNode* right);
	void operator=(const BSTreeNode&) = delete;
	BSTreeNode(const BSTreeNode&) = delete;
	~BSTreeNode();

public:
	void makeEmpty();
	Pair* getValue() const { return value; };
	BSTreeNode* getLeft() const { return left; };
	BSTreeNode* getRight() const { return right; };
	int numOfChildren() const;
	BSTreeNode* Max();
	void setValue() { (value->count)++; };
	void setValue(Pair* val);
	void setLeft(BSTreeNode* newLeft) { left = newLeft; };
	void setRight(BSTreeNode* newRight) { right = newRight; };
	/// Prints:
	void Inorder() const;
	void Preorder() const;
	void PostOrder() const;
};

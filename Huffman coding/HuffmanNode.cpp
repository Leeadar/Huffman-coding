#include "HuffmanNodeHeader.h"
#include <iostream>
using namespace std;

HuffmanNode::HuffmanNode()
{
	left = nullptr;
	right = nullptr;
}

HuffmanNode::HuffmanNode(char ch, int f)
{
	this->ch = ch;
	this->frequency = f;
	left = nullptr;
	right = nullptr;
}

HuffmanNode::~HuffmanNode()
{
	if (left != nullptr)
	{
		delete left;
	}
	if (right != nullptr)
	{
		delete right;
	}
	right = nullptr;
	left = nullptr;
}

const HuffmanNode& HuffmanNode::operator=(const HuffmanNode& other)
{
	if (this != &other)
	{
		ch = other.ch;
		frequency = other.frequency;
		left = other.left;
		right = other.right;
	}
	return *this;
}

// Recursive func to print inorder
void HuffmanNode::Inorder() const
{
	if (this->getLeft() != nullptr)
	{
		left->Inorder();
	}

	cout << "Key: " << ch << " frequency : = " << frequency << endl;

	if (this->getRight() != nullptr)
	{
		right->Inorder();
	}
}

// Caculate the Huffman code
void HuffmanNode::code(char* str, int index, int& sum)
{
	if ((this->getLeft() == nullptr) && (this->getRight() == nullptr))
	{
		if (ch == '\n')
		{
			cout << "'\\n' - ";
		}
		else if (ch == '\t')
		{
			cout << "'\\t' - ";
		}
		else
		{
			cout << "'" << ch << "' - ";
		}
		// print code
		for (int i = 0; i < index; i++)
		{
			cout << str[i];
		}
		// caculate frequency:
		if (index == 0)
		{
			cout << '1';
			sum += frequency;
		}
		else
		{
			sum += frequency * index;
		}
		cout << endl;
	}

	if (this->getLeft() != nullptr)
	{
		str[index] = '0';
		index++;
		left->code(str, index, sum);
		index--;
	}

	if (this->getRight() != nullptr)
	{
		str[index] = '1';
		index++;
		right->code(str, index, sum);
		index--;
	}
}
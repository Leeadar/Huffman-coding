#pragma once

// Huffman Node Class
class HuffmanNode
{
private:
	char ch; // only relevant in leaves
	int frequency; // how many times apears
	HuffmanNode* left, * right; // childrens

public:
	HuffmanNode();
	HuffmanNode(char ch, int f);
	const HuffmanNode& operator=(const HuffmanNode& other);
	HuffmanNode(const HuffmanNode&) = delete;
	~HuffmanNode();

public:
	HuffmanNode* getLeft() const { return left; };
	HuffmanNode* getRight() const { return right; };
	void SetLeft(HuffmanNode* node) { left = node; };
	void SetRight(HuffmanNode* node) { right = node; };
	int Frequency() const { return frequency; };
	void SetFrequency(int f) { frequency += f; };
	void SetChar(char c) { ch = c; };
	void Inorder() const;
	void code(char* str, int index, int& sum);
};
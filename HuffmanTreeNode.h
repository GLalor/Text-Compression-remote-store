#pragma once
class HuffmanTreeNode
{
	friend class HuffmanTree;
public:
	HuffmanTreeNode();
	HuffmanTreeNode(char theData, int frequency);
	bool isLeaf();
	friend bool operator>(const HuffmanTreeNode &lhs, const HuffmanTreeNode &rhs);		// Needed to be overloaded for priority_queue implementation was getting Compiler Error C2678
	friend bool operator<(const HuffmanTreeNode &lhs, const HuffmanTreeNode &rhs);		// Needed to be overloaded for priority_queue implementation was getting Compiler Error C2678
private:
	HuffmanTreeNode * leftChild;
	char data;
	int frequency;
	HuffmanTreeNode *rightChild;
};

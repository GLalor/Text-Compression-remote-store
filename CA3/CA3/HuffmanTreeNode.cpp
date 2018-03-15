#include "HuffmanTreeNode.h"
#include <algorithm>

using namespace std;


HuffmanTreeNode::HuffmanTreeNode() {
	data = NULL;
	frequency = NULL;
	leftChild = NULL;
	rightChild = NULL;
}

HuffmanTreeNode::HuffmanTreeNode(char dataIn, int frequencyIn) {
	data = dataIn;
	frequency = frequencyIn;
	leftChild = NULL;
	rightChild = NULL;
}

bool HuffmanTreeNode::isLeaf() {
	if (leftChild == NULL && rightChild == NULL) {
		return true;
	}
	return false;
}

// Needed to be overloaded for priority_queue implementation was getting Compiler Error C2678
bool operator >(const HuffmanTreeNode &lhs, const HuffmanTreeNode &rhs) {
	if (lhs.frequency > rhs.frequency){
		return true;
	}
	else {
		return false;
	}

}

// Needed to be overloaded for priority_queue implementation was getting Compiler Error C2678
bool operator <(const HuffmanTreeNode &lhs, const HuffmanTreeNode &rhs) {
	if (lhs.frequency < rhs.frequency) {
		return true;
	}
	else {
		return false;
	}

}
#include "HuffmanTree.h"
#include <iostream>

using namespace std;

HuffmanTree::HuffmanTree() {
	root = NULL;
}

void HuffmanTree::buildQueue(map<char, int> frequency) {
	if (root  == NULL) {
		root = new priority_queue<HuffmanTreeNode>();
	}
	for (auto character = frequency.begin(); character != frequency.end(); ++character) {
		root->push(HuffmanTreeNode(character->first, character->second));		// add each char and frequency to queue as a HuffmanTreeNode
	}
}

void HuffmanTree::printQueue() {
	printQueue(root);
}

void HuffmanTree::buildTree() {
	priority_queue<HuffmanTreeNode> forest;
	forest = *root;
	while (forest.size() > 1)
	{
		HuffmanTreeNode node1 = forest.top(); // take top node 
		forest.pop(); // remove node1
		HuffmanTreeNode node2 = forest.top(); // take top node 
		forest.pop(); // remove node2
		cout << "node 1 " << node1.data << "  node 2" << node2.data << endl;
		HuffmanTreeNode new_node = HuffmanTreeNode(NULL, node1.frequency + node2.frequency);
		new_node.leftChild = &node2;
		new_node.rightChild = &node2;
		forest.push(new_node);
	}
	root = &forest;
	auto cc = root->top();
}


void HuffmanTree::printQueue(priority_queue<HuffmanTreeNode> *subTreeRoot) {
	if (subTreeRoot == NULL) {
		cout << "Queue is empty";
	}
	else {
		priority_queue<HuffmanTreeNode>  queue = *subTreeRoot;
		HuffmanTreeNode temp;
		while (!queue.empty())
		{
			temp = queue.top();
			cout << temp.data << " " << temp.frequency << endl;
			queue.pop();
		}
		std::cout << std::endl;
	}
}

void HuffmanTree::buildTree(priority_queue<HuffmanTreeNode> *subTreeRoot){
	priority_queue<HuffmanTreeNode> forest;
	forest = *subTreeRoot;
	while (forest.size() > 1)
	{
		HuffmanTreeNode node1 = forest.top(); // take top node 
		forest.pop(); // remove node1
		HuffmanTreeNode node2 = forest.top(); // take top node 
		forest.pop(); // remove node2
		cout << "node 1 " << node1.data << "  node 2" << node2.data << endl;
		HuffmanTreeNode new_node = HuffmanTreeNode(NULL, node1.frequency + node2.frequency);
		new_node.leftChild = &node2;
		new_node.rightChild = &node1;
		forest.push(new_node);
	}
	subTreeRoot = &forest;
	auto cc = subTreeRoot->top();
}
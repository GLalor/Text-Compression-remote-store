#pragma once
#include "HuffmanTreeNode.h"
#include <string>
#include <queue>
#include <map>

using namespace std;

class HuffmanTree
{
public:
	HuffmanTree();
	void printQueue();
	void buildQueue(map<char, int> frequency);
	void buildTree();
	//void preOrderTraversal();
	//example of a specialised pre-order traversal
	//void getCodingMap();
protected:
	void printQueue(priority_queue<HuffmanTreeNode> *subTreeRoot);
	void buildQueue(priority_queue<HuffmanTreeNode> *subTreeRoot, map<char, int> frequency);
	void buildTree(priority_queue<HuffmanTreeNode> *subTreeRoot);
	//this will be used internally by the traversal above
	//void preOrderTraversal(HuffmanTreeNode *subTreeRoot);
	// specialised traversals may have other args,
	// depending what has to happen when a node is visited,	e.g.
	//void getCodingMap(HuffmanTreeNode *subTreeRoot, string codeStrToHere, map<char,int>* mapSoFar);
	priority_queue<HuffmanTreeNode> * root;
};
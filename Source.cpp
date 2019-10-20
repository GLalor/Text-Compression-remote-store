#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <queue>
#include "HuffmanTree.h"

using namespace std;

void getFrequency(map <char,int> &frequency, ifstream& file);

int main() {

	/***************************************************************************************
	*    
	*    finish task 2 tree creation and rest of ca
	*    
	*    
	***************************************************************************************/


	map<char, int> frequency = map<char,int>(); 
	string fileName;
	HuffmanTree huffmanTree = HuffmanTree();	// huffamn tree priority queue
	cout << "please enter the name of the file you would like to compress: ";
	getline(cin, fileName);
	ifstream file(fileName);
	if (file.is_open()) {
		getFrequency(frequency, file);

		/***************************************************************************************
		*    Title: std::map::begin, std::map::cbegin
		*    Author: cppreference.com
		*    Date: 12/03/2018
		*    Availability: http://en.cppreference.com/w/cpp/container/map/begin
		***************************************************************************************/
		// Code to loop through map
		// calls a_map.begin() and a_map.end()
		//for (auto character = frequency->begin(); character != frequency->end(); ++character) {
			//cout << character->first << ", " << character->second << endl;
			// Task 2 adding to queue
			//priorityQue.push(HuffmanTreeNode(character->first, character->second));		// add each char and frequency to queue as a HuffmanTreeNode
		//}
		huffmanTree.buildQueue(frequency);
		huffmanTree.printQueue();
		huffmanTree.buildTree();
	}
	else {
		cout << "Error opening file! File name -> " << fileName << endl;
	}
	system("pause");
	return 0;
}

// Task 1
void getFrequency(map <char, int> &frequency, ifstream& file) {
	char c;
	while (file.get(c)) {
		if (!frequency.empty()) {
			auto item = frequency.find(c);
			if (item != frequency.end()) {
				item->second++;
			}
			frequency.insert(pair<char, int >(c, 1));
		}
		else {
			frequency.insert(pair<char, int >(c, 1));
		}
	}
}
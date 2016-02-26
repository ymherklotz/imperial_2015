#include <iostream>

using namespace std;

typedef int list_t;

struct linkNode {
	list_t element;
	linkNode* next;
};

void addElement(linkNode*&, list_t&);
void addElementReverse(linkNode*&, list_t&);

int main() {
	linkNode* firstList = NULL;
	linkNode* secondList = NULL;

	int n;
	list_t el;
	cout << "Number of elements in list: ";
	cin >> n;
	for(int i = 0; i < n; ++i) {
		
	}
}

void addElement(linkNode* &hdList, list_t &el) {
	linkNode* newNode = new linkNode;
	newNode->element = el;
	newNode->next = hdList;
	hdList = newNode;
}

void addElementReverse(linkNode* &hdList, list_t &el) {
	if(hdList == NULL) {
					
	} else {
		
	}
}

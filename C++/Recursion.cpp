#include <iostream>

using namespace std;

typedef int list_t;

struct linkNode {
	list_t element;
	linkNode* next;
};

void addElement(linkNode*&, list_t&);
void addElementSort(linkNode*&, list_t&);
void printList(linkNode*&);
int listLengthRecursive(linkNode* hdList, int &len);
int listLength(linkNode*);
void printLinkedList(linkNode*);
void deallocateListRecursive(linkNode*&);
void deallocateList(linkNode*&);

int main() {
	linkNode* firstList = NULL;

	int n;
	list_t el;
	cout << "Number of elements in list: ";
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> el;
		addElementSort(firstList, el);
	}

	printLinkedList(firstList);
	deallocateListRecursive(firstList);
	cout << "firstList: " << firstList << endl;
	return 0;
}

void addElement(linkNode* &hdList, list_t &el) {
	linkNode* newNode = new linkNode;
	newNode->element = el;
	newNode->next = hdList;
	hdList = newNode;
}

void addElementSort(linkNode* &hdList, list_t &el) {
	if(hdList == NULL || hdList->element < el) {
		addElement(hdList, el);
	} else {
		linkNode* tmpNode = hdList;
		linkNode* prevNode = hdList;
		while(tmpNode != NULL && tmpNode->element >= el) {
			prevNode = tmpNode;
			tmpNode = tmpNode->next;
		}
		linkNode* newNode = new linkNode;
		newNode->next = tmpNode;
		newNode->element = el;
		prevNode->next = newNode;
	}
}

int listLengthRecursive(linkNode* hdList, int &len) {
	if(hdList != NULL) {
		listLengthRecursive(hdList->next, ++len);
	}
	return len;
}

int listLength(linkNode* hdList) {
	int len = 0;
	while(hdList != NULL) {
		++len;
	}
	return len;
}

void printLinkedList(linkNode* hdList) {
	if(hdList != NULL) {
		printLinkedList(hdList->next);
		cout << hdList->element << endl;
	}
}

void deallocateListRecursive(linkNode* &hdList) {
	if(hdList != NULL) {
		linkNode* tmpNode = hdList;
		hdList = hdList->next;
		delete tmpNode;
		deallocateListRecursive(hdList);
	}
}

void deallocateList(linkNode* &hdList) {
	while(hdList != NULL) {
		linkNode* tmpNode = hdList;
		hdList = hdList->next;
		delete tmpNode;	
	}
}

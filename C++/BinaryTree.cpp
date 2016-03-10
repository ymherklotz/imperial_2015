#include <iostream>

using namespace std;

typedef int tree_t;

struct treeNode {
	tree_t element;
	treeNode* left;
	treeNode* right;

	treeNode(tree_t el) {
		element = el;
		left = NULL;
		right = NULL;
	}
};

void addElement(treeNode*&, tree_t&);
void deallocateTree(treeNode*&);
void printTree(treeNode*);
void deleteFromRoot(treeNode*&, tree_t&);
int treeHeight(treeNode*);

int main() {
	treeNode* firstTree = NULL;
	tree_t newElement;
	int n;	

	cout << "Enter number of elements: ";
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> newElement;
		addElement(firstTree, newElement);
	}

	cout << "printing tree: " << endl;
	
	deallocateTree(firstTree);
	return 0;
}

void addElement(treeNode* &hdTree, tree_t &el) {
	if(hdTree == NULL) {
		treeNode* newTreeNode = new treeNode(el);
		hdTree = newTreeNode;
	} else if(el < hdTree->element) {
		addElement(hdTree->left, el);
	} else {
		addElement(hdTree->right, el);
	}
}

void deallocateTree(treeNode* &hdTree) {
	if(hdTree != NULL) {
		deallocateTree(hdTree->left);
		deallocateTree(hdTree->right);
		delete hdTree;
	}
}

void printTree(treeNode* hdTree) {
	if(hdTree != NULL) {
		printTree(hdTree->left);
		cout << hdTree->element;
		printTree(hdTree->right);
	}
}

void deleteFromRoot(treeNode* &hdTree, tree_t &el) {
	if(el < hdTree->element) {
		deleteFromRoot(hdTree->left, el);
	} else if(el > hdTree->element) {
		deleteFromRoot(hdTree->right, el);
	} else {
		// Do something
	}
}

int treeHeight(treeNode* hdTree) {
	// Do something
}

bool elementInTree(treeNode* hdTree, tree_t &el) {

}

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
void deleteRoot(treeNode*&);
void deleteLeftMost(treeNode*&, tree_t&);
int treeHeight(treeNode*);
int max(int&, int&);
bool isBalanced(treeNode*);
int abs(int&);
void rotateRight(treeNode*&);
void rotateLeft(treeNode*&);

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

	cout << endl << "printing tree: " << endl;

	printTree(firstTree);

	cout << endl << "head root node: " << firstTree->element << endl;
	//cout << endl << "which item would you want to delete?" << endl;
	//cin >> newElement;

	//deleteFromRoot(firstTree, newElement);

	//cout << endl << "printing tree again:" << endl;

	//printTree(firstTree);

	cout << endl << "Height of tree: " << treeHeight(firstTree) << endl;

	cout << endl << "Balanced Tree: " << isBalanced(firstTree) << endl;

	cout << endl << "Rotate right: " << endl;

	rotateLeft(firstTree);

	printTree(firstTree);

	cout << endl << "Height of tree: " << treeHeight(firstTree) << endl;
	cout << endl << "Balanced Tree: " << isBalanced(firstTree) << endl;	

	cout << endl << "new head root node: " << firstTree->element << endl;
	
	deallocateTree(firstTree);

	cout << endl << "successfully deallocated tree..." << endl;
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
		cout << hdTree->element << endl;
		printTree(hdTree->right);
	}
}

void deleteFromRoot(treeNode* &hdTree, tree_t &el) {
	if(hdTree != NULL) {
		if(hdTree->element == el) {
			deleteRoot(hdTree);
		} else if(hdTree->element > el) {
			deleteFromRoot(hdTree->left, el);
		} else {
			deleteFromRoot(hdTree->right, el);
		}
	}
}

void deleteRoot(treeNode* &hdTree) {
	treeNode* tmpPointer;
	tree_t leftMost;
	if(hdTree->right == NULL) {
		tmpPointer = hdTree->left;
		delete hdTree;
		hdTree = tmpPointer;
	} else {
		deleteLeftMost(hdTree, leftMost);
		hdTree->element = leftMost;
	}
}

void deleteLeftMost(treeNode* &hdTree, tree_t &leftMost) {
	if(hdTree->left == NULL) {
		leftMost = hdTree->element;
		deleteRoot(hdTree);
	} else {
		deleteLeftMost(hdTree->left, leftMost);
	}
}

int treeHeight(treeNode* hdTree) {
	if(hdTree == NULL) {
		return 0;
	}
	return 1 + max(treeHeight(hdTree->left), treeHeight(hdTree->right));
}

int max(int &a, int &b) {
	return (a >= b) ? a: b;
}

bool isBalanced(treeNode* hdTree) {
	int lh, rh;
	if(hdTree == NULL) {
		return true;
	}

	lh = treeHeight(hdTree->left);
	rh = treeHeight(hdTree->right);

	int diff = lh - rh;

	if(abs(diff) <= 1 && isBalanced(hdTree->left) && isBalanced(hdTree->right)) {
		return true;
	}
	return false;
}

int abs(int &a) {
	if(a > 0) {
		return a;
	}
	return (-1)*a;
}

void rotateRight(treeNode* &hdTree) {
	treeNode* tmpTree = hdTree;
	hdTree = hdTree->left;
	tmpTree->left = hdTree->right;
	hdTree->right = tmpTree;
}

void rotateLeft(treeNode* &hdTree) {
	treeNode* tmpTree = hdTree;
	hdTree = hdTree->right;
	tmpTree->right = hdTree->left;
	hdTree->left = tmpTree;
}

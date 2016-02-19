/* 
* @Author: yannherklotz
* @Date:   2016-02-08 22:20:52
* @Last Modified by:   yannherklotz
* @Last Modified time: 2016-02-09 12:43:15
*/

#include <iostream>

using namespace std;

typedef int list_t;

struct linkNode {
	list_t val;
	linkNode* next;
};

void addel(list_t, linkNode*&);
void deallocate(linkNode*&);
void printListOpposite(linkNode*);
void printListCorrect(linkNode*);
int listLength(linkNode*);
int deleteItem(linkNode*&, list_t);
linkNode* concatenateList(linkNode*, linkNode*);

int main(){
	linkNode* listA = NULL;
	linkNode* listB = NULL;
	linkNode* listC = NULL;

	int n;
	list_t el;

	cout << "How many elements: ";
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cout << "Enter element: ";
		cin >> el;

		addel(el, listA);
	}
	printListOpposite(listA);
	cout << endl;
	printListCorrect(listA);
	cout << "List Count: " << listLength(listA) << endl;
	cout << "which element to remove? ";
	cin >> n;
	deleteItem(listA, n);
	printListCorrect(listA);

	cout << "How many elements in list B: ";
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cout << "Enter element: ";
		cin >> el;

		addel(el, listB);
	}

	printListCorrect(listB);
	listC = concatenateList(listA, listB);
	cout << "Concatenated list:" << endl;
	printListCorrect(listC);
	cout << "delete from a: ";
	cin >> n;
	deleteItem(listA, n);
	cout << "delete from b: ";
	cin >> n;
	deleteItem(listB, n);
	cout << endl << "A" << endl;
	printListCorrect(listA);
	cout << "B" << endl;
	printListCorrect(listB);
	cout << "A+B" << endl;
	printListCorrect(listC);

	deallocate(listA);
	deallocate(listB);
	deallocate(listC);
    return 0;
}

void addel(list_t el, linkNode* &ln) {
	linkNode* tmp = new linkNode;
	tmp->val = el;
	tmp->next = ln;
	ln = tmp;
}

void deallocate(linkNode* &ln) {
	while(ln != NULL) {
		linkNode* nextln = ln->next;
		delete ln;
		ln = nextln;
	}
}

void printListOpposite(linkNode* ln) {
	while(ln != NULL) {
		cout << ln->val << endl;
		ln = ln->next;
	}
}

void printListCorrect(linkNode* ln) {
	if(ln != NULL) {
		printListCorrect(ln->next);
		cout << ln->val << endl;
	}
}

int listLength(linkNode* ln) {
	int count = 0;
	while(ln != NULL) {
		++count;
		ln = ln->next;
	}
	return count;
}

int findItem(linkNode* ln, list_t el) {
	int count = 0;
	while(ln != NULL) {
		if(ln->val == el) {
			return count;
		}
		++count;
	}
	return(-1);
}

int deleteItem(linkNode* &ln, list_t el) {
	linkNode* sp = ln;
	linkNode* fp = ln->next;

	if(sp->val == el) {
		ln = ln->next;
		delete sp;
	} else {
		while(fp != NULL) {
			if(fp->val == el) {
				sp->next = fp->next;
				delete fp;
				return 1;
			}
			fp = fp->next;
			sp = sp->next;
		}
	}
	return 0;
}

linkNode* concatenateList(linkNode* fl, linkNode* sl) {
	linkNode* tmpsl = NULL;
	linkNode* tmpfl = NULL;

	while(fl != NULL) {
		addel(fl->val, tmpfl);
		fl = fl->next;
	}
	while(sl != NULL) {
		addel(sl->val, tmpsl);
		sl = sl->next;
	}

	linkNode* tmp = tmpsl;
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = tmpfl;
	return tmpsl;
}

void reverseOrder(listNode* &ln) {
	linkNode* sp = ln;
	linkNode* tmp = ln;
	ln = ln->next;
	tmp->next = NULL;
	while(ln->next != NULL) {
		tmp = ln->next;
		ln->next = sp;
		sp = ln;
		ln = tmp;
	}
}
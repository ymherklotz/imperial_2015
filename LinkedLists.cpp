#include <iostream>

using namespace std;

struct intList {
	int val;
	intList* next_el;
};

int main() {
	intList* ilist = NULL;
	int el, n;

	cout << "How many elements do you want to add to the list?" << endl;
	cin >> n;
	cout << "Now please enter the " << n << " integers: " << endl;
	for(int i = 0; i < n; ++i) {
		cin >> el;
		intList* tmp = new intList;
		tmp->val = el;
		tmp->next_el = ilist;
		ilist = tmp;
	}
	cout << endl;
	intList* lit = ilist;
	while(lit != NULL) {
		cout << lit->val << endl;
		lit = lit->next_el;
	}

	while(ilist != NULL) {
		intList* tmpilist = ilist->next_el;
		delete ilist;
		ilist = tmpilist;
	}
	return 0;
}

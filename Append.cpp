#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> append(vector<int> v1, vector<int> v2) {
	for(int i = 0; i < v2.size(); i++) {
		v1.push_back(v2[i]);
	}
	return v1;
}

int main() {
	vector<int> a, b, c;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);
	c = append(a, b);
	cout << "c: ";
	for(int k = 0; k < c.size(); k++) {
		cout << c[k] << " ";
	}
	cout << endl;
	return 0;
}
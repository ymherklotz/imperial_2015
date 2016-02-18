m#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> v_union(vector<int>, vector<int>);
vector<int> v_intersection(vector<int>, vector<int>);
bool v_subset(vector<int>, vector<int>);

vector<int> v_union(vector<int> v1, vector<int> v2) {
	for(int i = 0; i < v2.size(); i++) {
		bool present = false;
		for(int j = 0; j < v1.size(); j++) {
			if(v2[i] == v1[j]) {
				present = true;
			}
		}
		if(!present) {
			v1.push_back(v2[i]);
		}
	}
	return v1;
}

vector<int> v_intersection(vector<int> v1, vector<int> v2) {
	vector<int> vInt;
	for(int i = 0; i < v2.size(); i++) {
		for(int j = 0; j < v1.size(); j++) {
			if(v2[i] == v1[j]) {
				vInt.push_back(v2[i]);
			}
		}
	}
	return vInt;
}

bool v_subset(vector<int> v1, vector<int> v2) {
	for(int i = 0; i < v2.size(); i++) {
		bool present = false;
		for(int j = 0; j < v1.size(); j++) {
			if(v1[j] == v2[i]) {
				present = true;
			}
		}
		if(!present) {
			return false;
		}
	}
	return true;
}

int main() {
	vector<int> a, b, c;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	b.push_back(1);
	b.push_back(1);
	b.push_back(2);
	cout << v_subset(a, b) << endl;
	return 0;
}
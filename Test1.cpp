#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct item {
	string name;
	int num;

	void print_str() {
		cout << name << ": " << num << endl;
	}
};

void merge_items(const vector<item> &vec1, vector<item> &vec2, vector<item> &vec_final) {
	// bool running = false;
	// for(int i = 0; i < vec1.size(); i++) {
	// 	if(vec1[i].name == vec2[i].name) {
	// 		vec2[i].num += vec1[i].num;
	// 		vec_final.push_back(vec2[i]);
	// 	} else if(vec1[i].name < vec2[i].name) {
	// 		vec_final.push_back(vec1[i]);
	// 		vec_final.push_back(vec2[i]);
	// 	} else {
	// 		vec_final.push_back(vec2[i]);
	// 		vec_final.push_back(vec1[i]);
	// 	}
	// }
	int count1, count2;
	count1 = 0; 
	count2 = 0;
	do {
		if(count1 < vec1.size()) {
			if(vec1[count1].name == vec2[count2].name) {
				vec2[count2].num += vec1[count1].num;
				vec_final.push_back(vec2[count2]);
				count1++;
				count2++;
			} else if(vec1[count1].name < vec2[count2].name) {
				vec_final.push_back(vec1[count1]);
				count1++;
			} else if(vec1[count1].name > vec2[count2].name) {
				vec_final.push_back(vec2[count2]);
				count2++;
			}
		} else {
			vec_final.push_back(vec2[count2]);
			count2++;
		}
	} while (vec_final.size() < vec1.size() + vec2.size());
	for(int i = vec1.size(); i < vec2.size(); i++) {
		vec_final.push_back(vec2[i]);
	}	
}

int main() {
	string ware1, ware2;
	ifstream fileware1, fileware2;
	vector<item> vecware1, vecware2, vecfinal;
	item tmpitem;

	ware1 = "Warehouse1.txt";
	ware2 = "Warehouse2.txt";

	fileware1.open(ware1);
	fileware2.open(ware2);

	if(!fileware1.is_open()) {
		cout << "couldn't open fileware1: '" << ware1 << "'" << endl;
	}
	if(!fileware2.is_open()) {
		cout << "couldn't open fileware2: '" << ware2 << "'" << endl;
	}

	while(fileware1 >> tmpitem.name >> tmpitem.num) {
		vecware1.push_back(tmpitem);
	}
	while(fileware2 >> tmpitem.name >> tmpitem.num) {
		vecware2.push_back(tmpitem);
	}

	merge_items(vecware2, vecware1, vecfinal);
	for(int i = 0; i < vecfinal.size(); i++) {
		cout << vecfinal[i].name << ": " << vecfinal[i].num << endl;
	}

	fileware1.close();
	fileware2.close();
	return(0);
}
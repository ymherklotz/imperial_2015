#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

void check_string();
// void translate(stringstream);

struct dict_type {
	string false_m, real_m;
};

void check_string() {
	ifstream dict_file;
	dict_type dict;
	vector<string> false_statement, real_statement, words;
	stringstream statement;
	string word, original;

	dict_file.open("DictRealEstate.txt");
	if(dict_file.is_open()){
		cout << "open\n";
		while(dict_file >> dict.false_m >> dict.real_m) {
			false_statement.push_back(dict.false_m);
			real_statement.push_back(dict.real_m);
		}
		cout << "finished...\n";
		dict_file.close();
	} 

	cout << "Enter Statement: ";
	getline(cin, original);
	statement << original;

	while(statement >> word) {
		words.push_back(word);
	}
	
	for(int i = 0; i < words.size(); i++) {
		for(int j = 0; j < false_statement.size(); j++) {
			if(words[i] == false_statement[j]) {
				words[i] = real_statement[j];
			}
		}
	}
	cout << "Translation: ";
	for(int k = 0; k < words.size(); k++) {
		cout << words[k] << " ";
	}
	cout << endl;
}

int main() {
	check_string();
	return(0);
}
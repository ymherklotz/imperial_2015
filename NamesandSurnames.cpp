#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct name {
	string first_name, last_name;

	string _str() {
		stringstream ss;
		ss << last_name << ", " << first_name << endl;
		return ss.str();
	}
};

int main() {
	name student_name;
	ifstream firstname, surname;
	ofstream firstFile, secondFile;

	firstname.open("Firstname.txt");
	surname.open("Surname.txt");
	firstFile.open("FirstFile.txt");
	secondFile.open("SecondFile.txt");

	while(firstname >> student_name.first_name) {
		surname >> student_name.last_name;
		firstFile << student_name.first_name << " " << student_name.last_name << endl;
		secondFile << student_name._str();
	}
	return 0;
}




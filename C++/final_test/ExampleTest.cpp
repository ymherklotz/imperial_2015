#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct element {
	string name;
	double weight;
	double value;

	double evaluateRatio() {
		return value / weight;
	}

	string formatString() {
		stringstream ss;
		ss << name << " w: " << weight << " v: " << value;
		return ss.str();
	}
};

void sortItems(element*&, int&, int&);
void selectItems(element*&, int&, element*&, int&, double&);
bool inArray(element*&, int&, element&);

int main() {
	ifstream inputFile;
	string fileName;
	int arraySize, count;
	element tmpEl;

	element* elArray;

	count = 0;

	cout << "Enter the name of the input file:" << endl;
	cin >> fileName;

	inputFile.open(fileName.c_str());
	if(!inputFile.is_open()) {
		cout << "Error opening file... Exiting now" << endl;
		exit(EXIT_FAILURE);
	}

	inputFile >> arraySize;

	elArray = new element[arraySize];

	while(inputFile >> tmpEl.name >> tmpEl.weight >> tmpEl.value) {
		elArray[count++] = tmpEl;
	}

	cout << endl << "input:" << endl;
	for(int i = 0; i < count; ++i) {
		cout << elArray[i].formatString() << endl;
	}

	sortItems(elArray, arraySize, count);
	cout << endl << "Sorted input by value / weight ratio:" << endl;
	for(int i = 0; i < count; ++i) {
		cout << elArray[i].formatString() << endl;
	}

	double usrIn = 0;
	element* targetArray = new element[arraySize];
	int targetCount;
	double wght, vlue;
	
	while(usrIn >= 0) {
		wght = 0;
		vlue = 0;
		cout << endl << "Enter target maximum weight (negative to exit): ";
		cin >> usrIn;
		if(usrIn >= 0) {
			selectItems(elArray, count, targetArray, targetCount, usrIn);
			cout << endl << "The best approximation for value and given weight is: " << endl << endl;
			for(int i = 0; i < targetCount; ++i) {
				cout << targetArray[i].formatString() << endl;
				wght += targetArray[i].weight;
				vlue += targetArray[i].value;
			}
			cout << endl << "weight: " << wght << endl << "value: " << vlue << endl;
		}
	}
	return 0;
}

void sortItems(element* &elArr, int &maxSize, int &count) {
	element* tmpArr = new element[maxSize];
	element tmpEl;

	for(int i = 0; i < count; ++i) {
		for(int j = 0; j < count; ++j) {
			if(!inArray(tmpArr, i, elArr[j])) {
				tmpEl = elArr[j];
			}
		}
		for(int j = 0; j < count; ++j) {
			if(!inArray(tmpArr, i, elArr[j]) && elArr[j].evaluateRatio() > tmpEl.evaluateRatio()) {
				tmpEl = elArr[j];
			}
		}
		tmpArr[i] = tmpEl;
	}

	delete[] elArr;
	elArr = tmpArr;
}

void selectItems(element* &elArr, int &count, element* &output, int &outCount, double &tarWeight) {
	outCount = 0;
	for(int i = 0; i < count; ++i) {
		if(elArr[i].weight < tarWeight) {
			output[outCount++] = elArr[i];
			tarWeight -= elArr[i].weight;
		}
	}
}

bool inArray(element* &elArr, int &count, element &el) {
	for(int i = 0; i < count; ++i) {
		if(elArr[i].name == el.name) {
			return true;
		}
	}
	return false;
}

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// point object structure
struct point {
	double x, y;

	void p_str() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

// declaration of method
void readPoints(string, int&, int&, point*&);

int main() {
	string fileLocation = "./PointFile.txt";
	// declares the size and capacity of the array which both have to be tracked and initialises them
	int size = 0;
	int capacity = 1;
	point* pArray = new point[capacity];
	readPoints(fileLocation, capacity, size, pArray);

	// prints out the content of the array
	for(int i = 0; i < size; i++) {
		pArray[i].p_str();
	}

	// prints out the characteristics of the array
	cout << "array capacity:\t\t" << capacity << endl << "array size:\t\t" << size << endl << "array physical size:\t" << size*sizeof(point) << " bits\t=\t" << size*sizeof(point)/8 << " bytes" << endl;

	delete[] pArray;
	return 0;
}

// method that creates the array
void readPoints(string fileloc, int &cpcty, int &sz, point* &pa) {
	// declares file and other variables
	ifstream pointFile;
	point tmpp;

	pointFile.open(fileloc);

	// Error opening file
	if(!pointFile.is_open()) {
		cout << "couldn't open input file" << endl;
		exit(EXIT_FAILURE);
	}

	// reads the two points from the file
	while(pointFile >> tmpp.x >> tmpp.y) {
		// increases the sz of the array
		sz++;
		// checks if the array is still large enough for the element
		if(sz <= cpcty) {
			// adds point to the end of the array
			pa[sz-1] = tmpp;
		} else {
			// if array isn't large enough creates new dynamic array
			// of two times the sz
			point* tmpa = new point[cpcty*=2];
			for(int i = 0; i < sz; i++) {
				tmpa[i] = pa[i];
			}
			// never have to delete the tmpa as it points to the new pa
			tmpa[sz-1] = tmpp;
			// delete old pa
			delete[] pa;
			pa = tmpa;
		}
	}

	pointFile.close();
}
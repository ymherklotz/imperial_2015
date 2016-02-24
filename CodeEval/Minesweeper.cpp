#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>
#include <unistd.h>

/*
 * <title>:			Minesweeper.cpp
 * <author>: 		Yann Herklotz
 * <date>:			25-01-2016
 * <description>:	This is a program that creates a Minesweeper field
 *
 */

// declares namespace
using namespace std;

// declares the function
void getMineField(int&, int&, string&, string*&);
void timing(int& , int&, string*&);

// main function that prints and inputs data
int main(int argc, char** argv) {
	// declares the variables
	ifstream file_stream;
	// strings for input
	string y_coord_str, x_coord_str, matrix;
	int y_coord, x_coord;
	// output string array
	string* field;
	string nothing;

	// opens and checks file
	file_stream.open(argv[1]);
	if(!file_stream.is_open()) {
		cout << "Couldn't open the file: " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}

	// reads the lines from the file and stops when there are none left
	while(getline(file_stream, y_coord_str, ',')) {
		getline(file_stream, x_coord_str, ';');
		getline(file_stream, matrix);

		// using stringstream to convert string to int
		stringstream ss;
		ss << y_coord_str << " " << x_coord_str;
		ss >> y_coord >> x_coord;

		// calls function and prints the results
		getMineField(x_coord, y_coord, matrix, field);
		cout << string(100, '\n');
		for(int i = 0; i < y_coord; ++i) {
			for(int j = 0; j < x_coord; ++j) {
				cout << field[i][j] << ' ';
			}
			cout << endl;
		}
		cin >> nothing;
	}
	// closes and deletes necessary variables
	delete[] field;
	file_stream.close();
	return 0;
}

// function that creates the minefield with numbers
void getMineField(int &x, int &y, string &mtrx, string* &fld) {
	// declares dynamic array from input
	fld = new string[1024];
	int int_sum;
	// puts subset correctly into dynamic array
	for(int i = 0; i < y; ++i) {
		fld[i] = mtrx.substr(i*x, x);
	}

	// checks all the cases around the current box
	for(int i = 0; i < y; ++i) {
		for(int j = 0; j < x; ++j) {
			int_sum = 0;
			if(fld[i][j] == '.') {
				if((i-1 >= 0) && (j-1 >= 0) && (fld[i-1][j-1] == '*')) {
					int_sum += 1;
				}
				if((i-1 >= 0) && (fld[i-1][j] == '*')) {
					int_sum += 1;
				}
				if((i-1 >= 0) && (j+1 >= 0) && (fld[i-1][j+1] == '*')) {
					int_sum += 1;
				}
				if((j+1 >= 0) && (fld[i][j+1] == '*')) {
					int_sum += 1;
				}
				if((i+1 >= 0) && (j+1 >= 0) && (fld[i+1][j+1] == '*')) {
					int_sum += 1;
				}
				if((i+1 >= 0) && (fld[i+1][j] == '*')) {
					int_sum += 1;
				}
				if((i+1 >= 0) && (j-1 >= 0) && (fld[i+1][j-1] == '*')) {
					int_sum += 1;
				}
				if((j-1 >= 0) && (fld[i][j-1] == '*')) {
					int_sum += 1;
				}
				char ch = '0' + int_sum;
				fld[i][j] = ch;
				timing(y, x, fld);
			}
		}
	}
}

void timing(int &y_c, int &x_c, string* &str_array) {
	usleep(100000);
	cout << string(100, '\n');
	for(int i = 0; i < y_c; ++i) {
		for(int j = 0; j < x_c; ++j) {
			cout << str_array[i][j] << ' ';
		}
		cout << endl;
	}
}
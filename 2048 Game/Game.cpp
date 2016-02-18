#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define GRIDSIZE 4
#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

using namespace std;

// defines the functions
void printGrid(int (&)[GRIDSIZE][GRIDSIZE]);
bool checkGameOver(int (&)[GRIDSIZE][GRIDSIZE]);

int main(int argc, char* argv[]) {
	// defines the 2D and tmp array
	int grid[GRIDSIZE][GRIDSIZE];
	string fileName;
	ifstream configFile;

	cout << "enter initial configuration file name:" << endl;
	cin >> fileName;

	// opens the user defined file
	configFile.open(fileName.c_str());

	if(configFile.is_open()) {
		for(int i = 0; i < GRIDSIZE; ++i) {
			for(int j = 0; j < GRIDSIZE; ++j) {
				configFile >> grid[i][j];
			}
		}
		configFile.close();
	} else {
		cout << "the file doesn't exist, using default start" << endl;
		// creates default grid
		for(int i = 0; i < GRIDSIZE; ++i) {
			for(int j = 0; j < GRIDSIZE; ++j) {
				grid[i][j] = 0;
			}
		}
		grid[GRIDSIZE-1][GRIDSIZE-1] = 2;
	}
    // prints the grid
	printGrid(grid);

	while(!checkGameOver(grid)) {
		
	}

    return 0;
}

void printGrid(int (&gridArray)[GRIDSIZE][GRIDSIZE]) {
	for(int i = 0; i < GRIDSIZE; ++i) {
		for(int j = 0; j < GRIDSIZE; ++j) {
			cout << gridArray[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void moveVertical() {

}

void moveHorizontal() {

}

void merge() {

}

bool checkGameOver(int (&gridArray)[GRIDSIZE][GRIDSIZE]) {
	for(int i = 0; i < GRIDSIZE; ++i) {
		for(int j = 0; j < GRIDSIZE; ++j) {
			if(gridArray[i][j] == 0) {
				return false;
			} else if(i > 0 && gridArray[i][j] == gridArray[i-1][j]) {
				return false;
			} else if(i < GRIDSIZE-1 && gridArray[i][j] == gridArray[i+1][j]) {
				return false;
			} else if(j > 0 && gridArray[i][j] == gridArray[i][j-1]) {
				return false;
			} else if(j < GRIDSIZE-1 && gridArray[i][j] == gridArray[i][j+1]) {
				return false;
			}
		}
	}
	return true;
}
/* 
 * includes necessary libraries
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
<<<<<<< HEAD
#include <ctime>
=======
>>>>>>> 0a5ef9619d59eeb0769e1195298ba2f5a37fc6b5

/* 
 * defines names for the constants we want to use
 * this is to make the code more readable 
 */
#define GRIDSIZE 	 4
#define BASE 		 2
#define UP 			'w'
#define DOWN 		's'
#define RIGHT 		'd'
#define LEFT 		'a'

using namespace std;

// declares the functions 
void printGrid(int(&) [GRIDSIZE][GRIDSIZE]);
void moveGrid(int(&) [GRIDSIZE][GRIDSIZE], char&);
void mergeArray(int*&, int&);
void placeBase(int (&) [GRIDSIZE][GRIDSIZE]);

bool checkGridChange(int (&) [GRIDSIZE][GRIDSIZE], int (&) [GRIDSIZE][GRIDSIZE]);
bool checkGameOver(int(&) [GRIDSIZE][GRIDSIZE]);

/* 
 * main function that handles all the i/o except for printing the grid
 * as this is easier done by a seperate function
 */
int main(int argc, char* argv[]) {
<<<<<<< HEAD
	// defines the 2D and tmp array that is used to check change
=======
	// defines the 2D and tmp array
>>>>>>> 0a5ef9619d59eeb0769e1195298ba2f5a37fc6b5
	int grid[GRIDSIZE][GRIDSIZE];
	int before[GRIDSIZE][GRIDSIZE];
	// defines tmp string file name to check if file exists
	string fileName;
	char usrInput;
	// defines input filestream for configFile
	ifstream configFile;

	// set random seed to be the current time
	srand(time(NULL));

	// gets the input from the user for the input file
	cout << "Enter initial configuration file name:" << endl;
	cin >> fileName;

	// opens the user defined file
	configFile.open(fileName.c_str());

	// enters the integers from the file into the array if file is correct
	if(configFile.is_open()) {
		for(int i = 0; i < GRIDSIZE; ++i) {
			for(int j = 0; j < GRIDSIZE; ++j) {
				configFile >> grid[i][j];
			}
		}
		configFile.close();
	} else {
		// if the file is not valid it will enter the default values of 0 and 2 in the
		// bottom right 
		cout << "The file doesn't exist, using default start" << endl;
		// creates default grid
		for(int i = 0; i < GRIDSIZE; ++i) {
			for(int j = 0; j < GRIDSIZE; ++j) {
				grid[i][j] = 0;
			}
		}
		grid[GRIDSIZE-1][GRIDSIZE-1] = BASE;
	}
	printGrid(grid);

	/*
	 * executes this loop while the game isn't over, which means that the user can
	 * still have turns and there are zero's left, as well as adjacent equivalent 
	 * numbers that can be added 
	 */
	while(!checkGameOver(grid)) {
		// gets user input
<<<<<<< HEAD
		cin >> usrInput;
=======
		cout << "Select move [w,a,s,d]: ";
		cin >> usrInput;
		cout << endl;
>>>>>>> 0a5ef9619d59eeb0769e1195298ba2f5a37fc6b5
		// copies the grid into the before grid
		for(int i = 0; i < GRIDSIZE; ++i) {
			for(int j = 0; j < GRIDSIZE; ++j)  {
				before[i][j] = grid[i][j];
			}
		}
		// moves grid in correct direction
		moveGrid(grid, usrInput);
		// check if grid has changed which means that the movement was valid
		if(checkGridChange(grid, before)){
<<<<<<< HEAD
			cout << endl;
=======
>>>>>>> 0a5ef9619d59eeb0769e1195298ba2f5a37fc6b5
			// places the random number in the correct base defined above
			placeBase(grid);
			// prints the grid
			printGrid(grid);
		}
	}
	cout << "game over" << endl;
    return 0;
}

/* 
 * prints the contents a 2D array with a constant size
 * so that the user can see the result of their input
 */
void printGrid(int (&gridArray)[GRIDSIZE][GRIDSIZE]) {
	for(int i = 0; i < GRIDSIZE; ++i) {
		for(int j = 0; j < GRIDSIZE; ++j) {
			cout << gridArray[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

/* 
 * handles the inputs of UP, DOWN, LEFT and RIGHT by the user and 
 * sends them to the merge algorithm in the correct order
 */
void moveGrid(int (&gridArray)[GRIDSIZE][GRIDSIZE], char &movDir) {
	// pointer that will point towards first element in array
	int* elementPtr;
	// defines the separation to the next element which 
	// says if it moves in rows or columns
	int separation;

	// if statements to find what direction the user wants to move the grid
	if(movDir == UP) {
		// separation set so that it goes up in rows
		separation = GRIDSIZE;
		for(int i = 0; i < GRIDSIZE; ++i) {
			// set elementpointer to be the first element in the rows
			elementPtr = &gridArray[0][i];
			// calls merge function
			mergeArray(elementPtr, separation);
		}
	} else if(movDir == DOWN) {
		separation = -GRIDSIZE;
		for(int i = 0; i < GRIDSIZE; ++i) {
			elementPtr = &gridArray[GRIDSIZE-1][i];
			mergeArray(elementPtr, separation);
		}
	} else if(movDir == LEFT) {
		// set separation to increment in columns
		separation = 1;
		for(int i = 0; i < GRIDSIZE; ++i) {
			elementPtr = gridArray[i];
			mergeArray(elementPtr, separation);
		}
	} else if(movDir == RIGHT) {
		separation = -1;
		for(int i = 0; i < GRIDSIZE; ++i) {
			elementPtr = &gridArray[i][GRIDSIZE-1];
			mergeArray(elementPtr, separation);
		}
	}
}

/* 
 * merges arrays together depending on the input
 */
void mergeArray(int* &arrayPointer, int &addrSep) {
	// defines array of one size larger so that all elements are moved correctly
	int nonZeroRow[GRIDSIZE+1];
	// sets all elements to 0
	for(int i = 0; i < GRIDSIZE+1; ++i) {
		nonZeroRow[i] = 0;
	}
	// sets the counter to 0
	int nonZeroCounter = 0;
	// sets all the elements in the array to be the nonzero elements
	// pointed to by the pointer
	for(int i = 0; i < GRIDSIZE; ++i) {
		if(*(arrayPointer+addrSep*i) != 0) {
			nonZeroRow[nonZeroCounter++] = *(arrayPointer+addrSep*i);
		}
	}
	for(int i = 0; i < nonZeroCounter; ++i) {
		// if two adjacent cells are equal multiply by the base
		if(nonZeroRow[i] == nonZeroRow[i+1]) {
			nonZeroRow[i] *= BASE;
			// then move all the other elements up
			for(int j = i+1; j < GRIDSIZE; ++j) {
				nonZeroRow[j] = nonZeroRow[j+1];
			}
		}
	}
	// set all the pointer locations to be equal to the elements in the array
	for(int i = 0; i < GRIDSIZE; ++i) {
		*(arrayPointer+addrSep*i) = nonZeroRow[i];
	}
}

/*
 * adds a base num at a random location where a zero was
 */
void placeBase(int (&gridArray)[GRIDSIZE][GRIDSIZE]) {
	// 2D array that will hold locations of the zeros
	int zeroArray[GRIDSIZE*GRIDSIZE][2];
	// sets the 0 counter
	int zeroCount = 0;
	for(int i = 0; i < GRIDSIZE; ++i) {
		for(int j = 0; j < GRIDSIZE; ++j) {
			if(gridArray[i][j] == 0) {
				// sets the x and y values in the zero array
				zeroArray[zeroCount][0] = i;
				zeroArray[zeroCount++][1] = j;
			}
		}
	}
	// gets a random number
	int randomLoc = rand() % zeroCount;
	// sets the random location in the grid to equal that value
	gridArray[zeroArray[randomLoc][0]][zeroArray[randomLoc][1]] = BASE;
}

/* 
 * checks if the two grids are the same
 * if they are this means it will not add the random 2
 * and not print the grid
 */
bool checkGridChange(int (&gridArray)[GRIDSIZE][GRIDSIZE], int (&beforeGrid)[GRIDSIZE][GRIDSIZE]) {
	for(int i = 0; i < GRIDSIZE; ++i) {
		for(int j = 0; j < GRIDSIZE; ++j) {
			if(gridArray[i][j] != beforeGrid[i][j]) {
				// if it finds a value that doesn't match, grid must have changed hence return true
				return true;
			}
		}
	}
	return false;
}

/* 
 * checks if the game is over by checking if 0's are present
 * or if there are equal numbers side by side
 */
bool checkGameOver(int (&gridArray)[GRIDSIZE][GRIDSIZE]) {
	// uses two for loops to go through all boxes in the grid
	for(int i = 0; i < GRIDSIZE; ++i) {
		for(int j = 0; j < GRIDSIZE; ++j) {
			// checks if the current box is a 0
			if(gridArray[i][j] == 0) {
				// returns false as this means the game isn't over
				return false;
			} 
			 // if not it checks if there are any repeating numbers around 
			 // it as this means they can add 
			else if(i > 0 && gridArray[i][j] == gridArray[i-1][j]) {
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
	// if none of the if statements is true it will end the games
	return true;
<<<<<<< HEAD
}
=======
}
>>>>>>> 0a5ef9619d59eeb0769e1195298ba2f5a37fc6b5

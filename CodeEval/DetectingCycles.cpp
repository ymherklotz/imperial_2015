#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

int find_cycle(int*&, int*&);

int main(int argc, char** argv) {
	// Initialisation of arrays and filestream
	ifstream file_stream;
	int* tmp_array = new int[50];
	int* cycle_array;
	int array_count, cycle_count;
	string tmp_str;
	stringstream str_stream;

	// Opens the file and checks if no error occured
	file_stream.open(argv[1]);
	// file_stream.open("./list.txt");
	if(!file_stream.is_open()) {
		cout << "Couldn't open the file: " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}

	// Waits till file ends
	while(getline(file_stream, tmp_str)) {
		// Init counter
		array_count = 0;
		cycle_array = new int[50];
		// Set Stringstream
		str_stream.str(tmp_str);
		// Put stringstream into int array
		while(str_stream >> tmp_array[array_count]) {
			++array_count;
		}
		// Clear ss
		str_stream.clear();
		// Get cycles
		cycle_count = find_cycle(tmp_array, cycle_array);
		// Delete int array
		delete[] tmp_array;
		tmp_array = new int[50];
		// Print cycles
		for(int i = 0; i < cycle_count; ++i) {
			cout << cycle_array[i] << " ";
		}
		cout << endl;
		// Delete cycle array
		delete[] cycle_array;
		cycle_count = 0;
	}

	// Closing sequence
	file_stream.close();
	delete[] tmp_array;
	return 0;
}

// Takes input of a vector by reference and makes it the vector containing the sequence
int find_cycle(int* &f_list, int* &cycle) {
	// Defines the 2 pointers and the positioning of sequence
	int s_point, f_point, mu, lambda, power, count;
	count = 0;
	s_point = f_list[count];
	f_point = f_list[++count];
	power = 1;
	lambda = 1;

	// Goes through list and increments s_point by a factor of 2^i
	// If s = f then there is a cycle with length of current lambda
	while(s_point != f_point) {
		// Increases power as it went through all of lambda
		if(power == lambda) {
			s_point = f_point;
			power *= 2;
			// Reset Lambda so that it always stays correct
			lambda = 0;
		}
		// Increments the f_pointer by 1 and lambda
		f_point = f_list[++count];
		++lambda;
	}

	// Init mu, the distance from the start
	mu = 0;
	// Reset count
	count = 0;
	// Set the s and f to be lambda apart and then cycle through the sequence
	s_point = f_list[count];
	f_point = f_list[lambda];
	// Stops when they are equal because it means it found mu
	while(s_point != f_point) {
		++count;
		s_point = f_list[count];
		f_point = f_list[lambda+count];
		++mu;
	}
	// Set cycle to be equal to the first appearance of the cycle
	count = 0;
	for(int i = mu; i < mu+lambda; ++i) {
		cycle[count] = f_list[i];
		++count;
	}
	return count;
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	ifstream file_stream;
	int num, array_size;
	string* lines = new string[1024];
	bool sorted = true;
	string tmp;

	array_size = 0;
	file_stream.open(argv[1]);
	file_stream >> num;
	while(getline(file_stream, lines[array_size])) {
		++array_size;
	}
	while(sorted) {
		sorted = false;
		for(int i = 1; i < array_size; ++i) {
			if(lines[i].length() > lines[i-1].length()) {
				tmp = lines[i];
				lines[i] = lines[i-1];
				lines[i-1] = tmp;
				sorted = true;
			}
		}
	}
	for(int j = 0; j < num; ++j) {
		cout << lines[j] << endl;
	}

	file_stream.close();
	delete[] lines;
	return 0;
}
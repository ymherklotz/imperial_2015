#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*      8 * * * * * * * *
        7 * * * * * * * *
        6 * * _ * _ * * *
        5 * _ * * * _ * *
        4 * * * k * * * *
        3 * _ * * * _ * *
        2 * * _ * _ * * *
        1 * * * * * * * *
          a b c d e f g h      */

void find_possible_jumps(string&, string*&, int&);

int main(int argc, char** argv) {
	ifstream file_stream;
	string tmp_str;
	string* post_loc;
	int post_loc_count;

	file_stream.open(argv[1]);
	//file_stream.open("./KnightLocations.txt");
	if(!file_stream.is_open()) {
		cout << "Couln't open file: " << argv[1] << endl;
	}

	while(getline(file_stream, tmp_str)) {
		find_possible_jumps(tmp_str, post_loc, post_loc_count);
		for(int i = 0; i < post_loc_count; ++i) {
		if(i != post_loc_count-1) {
			cout << post_loc[i] << " ";
		} else {
			cout << post_loc[i] << endl;
		}
	}

	}

	delete[] post_loc;
	file_stream.close();
	return 0;
}

void find_possible_jumps(string &knight_loc, string* &chess_loc, int &count) {
	int posx, negx, posy, negy, pos2x, neg2x, pos2y, neg2y;
	chess_loc = new string[8];
	char* ch = new char[2];
	count = 0;

	posx = int(knight_loc[0]) + 2;
	posy = int(knight_loc[1]) + 1;
	negx = int(knight_loc[0]) - 2;
	negy = int(knight_loc[1]) - 1;
	pos2x = int(knight_loc[0]) + 1;
	pos2y = int(knight_loc[1]) + 2;
	neg2x = int(knight_loc[0]) - 1;
	neg2y = int(knight_loc[1]) - 2;

	if(negx > 96) {
		if(negy > 48) {
			ch[0] = negx;
			ch[1] = negy;
			chess_loc[count] = ch;
			++count;
		} if(posy < 57) {
			ch[0] = negx;
			ch[1] = posy;
			chess_loc[count] = ch;
			++count;
		}
	} 

	if(neg2y > 48) {
		if(neg2x > 96) {
			ch[0] = neg2x;
			ch[1] = neg2y;
			chess_loc[count] = ch;
			++count;
		}
	} if(pos2y < 57) {
		if(neg2x > 96) {
			ch[0] = neg2x;
			ch[1] = pos2y;
			chess_loc[count] = ch;
			++count;
		}
	} if(neg2y > 48) {
		if(pos2x < 105) {
			ch[0] = pos2x;
			ch[1] = neg2y;
			chess_loc[count] = ch;
			++count;
		}
	} if(pos2y < 57) {
		if(pos2x < 105) {
			ch[0] = pos2x;
			ch[1] = pos2y;
			chess_loc[count] = ch;
			++count;
		}
	} 

	if(posx < 105) {
		if(negy > 48) {
			ch[0] = posx;
			ch[1] = negy;
			chess_loc[count] = ch;
			++count;
		} if(posy < 57 ) {
			ch[0] = posx;
			ch[1] = posy;
			chess_loc[count] = ch;
			++count;
		} 
	}
	delete[] ch;
}
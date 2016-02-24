#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int usrNum, usrNum1, usrNum2;
	int count;

	cout << "Please Enter a range: ";
	cin >> usrNum1 >> usrNum2;
	
	cout << "\nnumber\tsteps\n";
//	cout << usrNum1 << "\t" << usrNum2 << endl;
	for(usrNum=usrNum1; usrNum<=usrNum2; usrNum++) {
		count = 0;
		int initNum = usrNum;
		while(initNum > 1) {
			if(initNum % 2 == 0) {
				initNum = initNum / 2;
			}
			else {
				initNum = initNum*3 + 1;
			}

			count ++;
		}
		cout << usrNum << "\t" << count << "\t";
		for(int x = 0; x < count; x++) {
			cout << "*";
		}
		cout << endl;
	}	
}
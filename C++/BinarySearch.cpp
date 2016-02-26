#include <iostream>

using namespace std;

int main() {
	double result, num, divi;
	result = 0.0;
	num = 1.0;
	divi = 1.0;

	for(int i = 2; i < 1000; i++) {
		for(int j = 2; j < 1000; j++) {
			num = (double)i;
			divi = (double)j;
			result = (double)(num/divi)*((num-1)/(divi-1));
			if(result == 0.5) {
				cout << i << " " << j << endl;
			}
			cout << j << endl;
		}
	}
	return 0;
}
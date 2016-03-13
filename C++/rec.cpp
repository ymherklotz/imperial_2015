#include <iostream>

using namespace std;

void returnDigits(int&);

int main(int argc, char** argv) {
	int n;
	cout << "input a number to seperate:" << endl;
	cin >> n;
	returnDigits(n);
	return 0;
}

void returnDigits(int &n) {
	if(n > 10) {
		int d = n % 10;
		n /= 10;
		returnDigits(n);
		cout << d << endl;
	} else {
		cout << n << endl;
	}
}

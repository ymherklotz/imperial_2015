#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int num;
	cout << "Please enter a number: ";
	cin >> num;
	if(num % 2 == 0) {
		cout << "even" << endl;
	}
	else {
		cout << "odd" << endl;
	}

	return 0;
}
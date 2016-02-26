#include <iostream>
#include <cmath>

using namespace std;

int mgcd(int a, int b) {
	if(a % b != 0) {
		mgcd(b, a % b);
	} else {
		cout << "\nGreatest common divisor: " << b  << endl;
	}	
}

int main() {
	int x, y;
	cout << "Enter 2 numbers: ";
	cin >> x >> y;
	mgcd(x, y);
}

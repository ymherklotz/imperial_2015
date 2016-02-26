#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct point {
	double x;
	double y;

	string returnString() {
		stringstream ss;
		ss << "(" << x << ", " << y << ")";
		return ss.str();
	}
};

int main() {
	point userPt;

	cout << "Please enter a point: ";
	cin >> userPt.x >> userPt.y;
	cout << "Your point was: " << userPt.returnString() << endl;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
	int a = 15;
	int* point = &a;

	cout << "a: " << a << ", &a: " << &a << ", point: "
			<< point << ", &point: " << &point << ", *point: " << 
			*point << endl;

}
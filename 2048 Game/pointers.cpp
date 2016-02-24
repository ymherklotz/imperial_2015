#include <iostream>

using namespace std;

int main() {
	int array[2];
	array[0] = 5;
	array[1] = 2;

	cout << "array: " << array << ", array2: " << &array[1] << endl;
	cout << "size of int: " << sizeof(int) << endl;
}

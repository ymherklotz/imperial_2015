#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double> vector_sum(vector<double>, vector<double>);
double vector_product(vector<double>, vector<double>);

vector<double> vector_sum(vector<double> v1, vector<double> v2) {
	vector<double> vSum;
	for(int i = 0; i < v1.size(); i++) {
		vSum.push_back(v1[i] + v2[i]);
	}
	return vSum;
}

double vector_product(vector<double> v1, vector<double> v2) {
	double vProduct;
	for(int j = 0; j < v1.size(); j++) {
		vProduct += v1[j] * v2[j];
	}
	return vProduct;
}

int main() {
	vector<double> v1, v2, vSum;
	double tmp, tmp2, vProduct;
	int dimensions, x;
	cout << "How many dimensions are you using? ";
	cin >> dimensions;
	do {
		cout << "Please enter both vectors: ";
		cin >> tmp >> tmp2;
		v1.push_back(tmp);
		v2.push_back(tmp2);
		x++;
	} while (x < dimensions);
	vSum = vector_sum(v1, v2);
	vProduct = vector_product(v1, v2);
	cout << "Sum: ";
	for(int k = 0; k < vSum.size(); k++) {
		cout << vSum[k] << " ";
	}
	cout << "\nProduct: " << vProduct << endl;
	return 0;
}
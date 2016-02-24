#include <iostream>

using namespace std;

int main() {
	int count, triangle, k, result;
	int* allcount = new int[100000000000];
	k = 0;
	result = 1;
	for(int i = 2; i < 50000; ++i) {
		triangle = (i*(i+1))/2;
		int realtriangle = triangle;
		for(int j = 2; j <= triangle; ++j) {
			count = 0;
			while(triangle % j == 0) {
				triangle /= j;
				++count;
			}
			allcount[k] = count;
			++k;
		}
		for(int j = 0; j < k; ++j) {
			result *= (allcount[j]+1);
		}
		if(result > 500) {
			cout << realtriangle << endl;
		}
	}
}
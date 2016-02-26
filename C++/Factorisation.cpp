#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void is_prime(int);
void print_vector(vector<int>);

void is_prime(int x) {
	int original = x;
	vector<int> primes, factors;
	primes.push_back(2);
	primes.push_back(3);

	for(int i = 5; i <= x; i++) {
		bool itsPrime = false;
		for(int j = 0; j < primes.size(); j++) {
			if(i % primes[j] == 0) {
				itsPrime = false;
				break;
			} else {
				itsPrime = true;
			}
		}
		if(itsPrime) {
			primes.push_back(i);
		}
	}
	// cout << "Prime numbers to consider: ";
	// print_vector(primes);
	while(x != 1) {
		for(int l = 0; l < primes.size(); l++) {
			if(x % primes[l] == 0) {
				factors.push_back(primes[l]);
				x = x / primes[l];
				break;
			}
		}
	}
	cout << "Factors of " << original << ": ";
	print_vector(factors);
}

void print_vector(vector<int> v) {
	for(int k = 0; k < v.size(); k++) {
		cout << v[k] << " ";
	}
	cout << endl;
}

int main() {
	is_prime(103);
	return 0;
}
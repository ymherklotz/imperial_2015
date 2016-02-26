#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	double input, maxtmp, maxloc, mintmp, minloc, 
			addtmp, average;
	vector<double> vin;

	cout << "Enter Number <q to exit>: ";
	cin >> input;

	do {
		cout << "Enter Number <q to exit>: ";
		vin.push_back(input);
	} while(cin >> input);

	mintmp = vin[0];
	maxtmp = vin[0];
	addtmp = 0;

	// cout << "values: " << mintmp << ", " << maxtmp << endl;

	for(int i = 0; i < vin.size(); i++) {
		if(maxtmp <= vin[i]) {
			maxtmp = vin[i];
			maxloc = i;
		} else if (mintmp >= vin[i]) {
			mintmp = vin[i];
			minloc = i;
		}
		addtmp += vin[i];
	}
	average = addtmp / vin.size();
	cout << "\nmin: " << mintmp << " at pos: " << minloc << "\nmax: " 
			<< maxtmp << " at pos: " << maxloc << "\naverage: " << 
			average << endl;
	return 0;
}

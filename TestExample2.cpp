#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct codon_pairing {
	string amino;
	string codon;

	void prnt_pair() {
		cout << amino << " " << codon << endl;
	}
};

void wrong_entries(vector<codon_pairing>&, vector<codon_pairing>&, vector<codon_pairing>&);

int main() {
	vector<codon_pairing> experiment_log, correct_pair, wrong_pairs;
	codon_pairing tmpcp;

	cout << "Please enter the experiment log (end end pair terminates):" << endl;

	do {
		cin >> tmpcp.amino >> tmpcp.codon;
		experiment_log.push_back(tmpcp);
	} while(tmpcp.amino != "end" && tmpcp.codon != "end");

	cout << "Please enter the known correct pairings (end end pair terminates):" << endl;

	do {
		cin >> tmpcp.amino >> tmpcp.codon;
		correct_pair.push_back(tmpcp);
	} while(tmpcp.amino != "end" && tmpcp.codon != "end");
	wrong_entries(experiment_log, correct_pair, wrong_pairs);
	cout << "Wrong entries:" << endl;
	for(int i = 0; i < wrong_pairs.size(); ++i) {
		wrong_pairs[i].prnt_pair();
	}
}

void wrong_entries(vector<codon_pairing>& exp_log, vector<codon_pairing>& crrct_pair, vector<codon_pairing>& wrng_pairs) {
	bool present = false;
	for(int i = 0; i < exp_log.size(); ++i) {
		for(int j = 0; j < crrct_pair.size(); ++j) {
			if(exp_log[i].amino == crrct_pair[j].amino && exp_log[i].codon == crrct_pair[j].codon) {
				present = true;
			}
		}
		if(!present) {
			wrng_pairs.push_back(exp_log[i]);
		}
		present = false;
	}
}
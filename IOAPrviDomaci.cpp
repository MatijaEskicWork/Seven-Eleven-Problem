#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

vector<int> findFactors(long long N, int maxx) {
	vector<int> factors;
	int root = sqrt(N);
	int end = min(root, maxx);
	for (int i = 1; i <= end; i++) {
		if (N % i == 0) {
			factors.push_back(i);
			if (N / i <= end) factors.push_back(N / i);
		}
	}
	sort(factors.begin(), factors.end());
	return factors;
}


int main() {
	cout << fixed;
	cout << setprecision(2);
	double goal = 7.11;
	int numbers = 4;
	const long long goalExtended = goal * 100000000LL;
	const int MAX = goal * 100;
	long long calls = 0;
	float sol[4];
	bool ok = false;
	for (int i = 1; i <= MAX - numbers + 1; i++) {
		//if (ok) break;
		for (int j = 1; j <= MAX - i; j++) {
			//if (ok) break;
			for (int k = 1; k <= MAX - (i + j); k++) {
				//if (ok) break;
				for (int l = 1; l <= MAX - (i + j + k); l++) {
					calls++;
					if (i + j + k + l == MAX &&  (long long) 1LL * i * j * k * l == goalExtended) {
						//ok = true;
						sol[0] = i / 100.0;
						sol[1] = j / 100.0;
						sol[2] = k / 100.0;
						sol[3] = l / 100.0;
						//break;
					}

				}
			}
		}
	}
	cout << "Solution a): (";
	for (int i = 0; i < 4; i++) {
		if (i != 3) {
			cout << sol[i] << ", ";
		}
		else {
			cout << sol[i] << ")" << endl;
		}
	}
	cout << "Maximum number of optimization function calls a): " << calls << endl << endl;
	//Assignment b)
	float solB[4];
	long long callsB = 0;
	ok = false;
	for (int i = 1; i <= MAX - numbers + 1; i++) {
		//if (ok) break;
		for (int j = 1; j <= MAX - i; j++) {
			//if (ok) break;
			for (int k = 1; k <= MAX - (i + j); k++) {
				callsB++;
				int l = MAX - (i + j + k);
				if ((long long)1LL * i * j * k * l == goalExtended) {
					//ok = true;
					solB[0] = i / 100.0;
					solB[1] = j / 100.0;
					solB[2] = k / 100.0;
					solB[3] = l / 100.0;
					//break;
				}
			}
		}
	}
	cout << "Solution b): (";
	for (int i = 0; i < 4; i++) {
		if (i != 3) {
			cout << solB[i] << ", ";
		}
		else {
			cout << solB[i] << ")" << endl;
		}
	}
	cout << "Maximum number of optimization function calls b): " << callsB << endl << endl;	
	double ratio = (double)calls / callsB;
	if (ratio > 1.00) {
		cout << "The first aproach is faster " << ratio << " times." << endl;
	}
	else if (ratio < 1.00) {
		ratio = 1.00 / ratio;
		cout << "The second aproach is faster " << ratio << " times." << endl;
	}
	else {
		cout << "Both aproach have same speed." << endl;
	}
	vector<int> factors;
	vector<float> solBonus;
	int cntBonus = 0;
	for (int i = 1; i < 1000; i++) {
		long long number = i * 1000000LL;
		factors = findFactors(number, i);
		int sz = factors.size();
		ok = false;
		for (int j = 0; j < sz; j++) {
			//if (ok) {
				//break;
			//}
			for (int k = j; k < sz; k++) {
				//if (ok) {
					//break;
				//}
				for (int l = k; l < sz; l++) {
					int m = i - (factors[j] + factors[k] + factors[l]);
					int maxx = max(max(factors[j], factors[k]), factors[l]);
					if (m < maxx) continue;
					if ((long long)1LL * m * factors[j] * factors[k] * factors[l] == number) {
						if (cntBonus == 0) {
							cout << endl << "List of all solutions for bonus question:" << endl;
						}
						cntBonus++;
						cout << cntBonus << ". " << i / 100.00 << ": " << "(" << factors[j] / 100.00 << ", " << factors[k] / 100.00 << ", " << factors[l] / 100.0 << ", " << m / 100.0 << ")" << endl;
						if (!ok) {
							solBonus.push_back(i / 100.0);
						}
						ok = true;
						break;
					}
				}
			}
		}
	}

	cout << endl << "List of all numbers for bonus question:" << endl;
	for (int i = 0; i < solBonus.size(); i++) {
		cout << i + 1 << ". " << solBonus[i] << endl;
	}


}
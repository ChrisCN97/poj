// poj 1023
// 2019.3.15

/* input:
4
3
pnp
6
4
ppnn
10
7
pnppnnp
0
7
pnppnnp
14
*/

/* output:
Impossible
1110
*/

// 

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int caseNum, bit, i, m;
	string s;
	long long target, close;
	bool wrong, *result;
	cin >> caseNum;
	while (caseNum--) {
		cin >> bit >> s >> target;
		if (target == 0) {
			for (i = 0; i < bit; i++)
				cout << "0";
			cout << endl;
			continue;
		}
		close = 0;
		wrong = false;
		result = new bool[bit];
		for (i = 0; i < bit; i++)
			result = 0;
		reverse(s.begin(), s.end());
		if (target > 0) {
			for (i = 0; i < bit; i++) {
				if (s[i] == 'p') {
					close += pow(2, i);
					result[i] = 1;
					if (close == target)
						break;
					if (close > target) {
						for (m = 0; m < bit; m++) {
							if (s[m] == 'n') {
								close -= pow(2, i);
								result[i] = 1;
								if (close == target)
									break;
								if (close < target) {

								}
							}
						}
						if (!wrong)
							break;
					}
				}
			}
		}

		if (wrong) cout << "Impossible" << endl;
		else {
			for (i = bit - 1; i >= 0; i--) {
				cout << int(result[i]);
			}
			cout << endl;
		}
	}

	return 0;
}
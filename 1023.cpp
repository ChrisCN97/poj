// poj 1023
// 2019.3.15

/* input:
5
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
4
ppnn
-3
*/

/* output:
Impossible
1110
0000000
0010010
*/

// 

#include <iostream>
#include <string>
using namespace std;

int main() {
	int caseNum, bit, i;
	string s;
	long long target;
	bool *result;
	cin >> caseNum;
	while (caseNum--) {
		cin >> bit >> s >> target;
		result = new bool[bit];
		for (i = 0; i < bit; i++)
			result[i] = 0;
		for (i = bit - 1; i >= 0; i--) {
			if (target & 1) {
				result[i] = 1;
				target >>= 1;
				if (s[i] == 'n')
					target++;
				
			}
			else {
				result[i] = 0;
				target >>= 1;
			}
		}
		if (target == 0) {
			for (i = 0; i < bit; i++)
				cout << result[i];
			cout << endl;
		}
		else
			cout << "Impossible" << endl;

		delete result;
	}

	return 0;
}
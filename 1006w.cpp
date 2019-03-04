// poj 1006
// 2019.3.4

/* input:
0 0 0 0
0 0 0 100
5 20 34 325
4 5 6 7
283 102 23 320
203 301 203 40
-1 -1 -1 -1
*/

/* output:
Case 1: the next triple peak occurs in 21252 days.
Case 2: the next triple peak occurs in 21152 days.
Case 3: the next triple peak occurs in 19575 days.
Case 4: the next triple peak occurs in 16994 days.
Case 5: the next triple peak occurs in 8910 days.
Case 6: the next triple peak occurs in 10789 days.
*/

// cycle: 23, 28, 33
// 5 20 34 => 5 20 1

#include <iostream>
using namespace std;

int main() {
	const int PC = 23, EC = 28, IC = 33;
	int p, e, i, d, pcc, ecc, icc;
	while(true) {
		cin >> p >> e >> i >> d;
		if (p == -1 && e == -1 && i == -1 && d == -1) break;
		pcc = p % PC;
		ecc = e % EC;
		icc = i % IC;
		for (int i = 1;; i++) {

		}
	}

	return 0;
}
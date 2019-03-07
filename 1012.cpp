// poj 1012
// 2019.3.7

/* input:
3
4
0
*/

/* output:
5
30
*/

#include <iostream>
using namespace std;

int main() {
	int k, now, tNow, m, left;
	int joseph[14] = { 0 };
	do {
		cin >> k;
		if (k == 0) break;
		if (joseph[k] != 0) {
			cout << joseph[k] << endl;
			continue;
		}
		m = k + 1;
		left = 2 * k;
		now = 1;
		do {
			tNow = ((now + m - 1) % left) == 0 ? left : ((now + m - 1) % left);
			if (tNow < (k + 1)) {
				m++;
				left = 2 * k;
				if (m % left == 1) m += k;
				now = 1;
				continue;
			}
			else {
				now = tNow == left ? 1 : tNow;
				left--;
			}
		} while (left != k);
		cout << m << endl;
		joseph[k] = m;
	} while (true);

	return 0;
}
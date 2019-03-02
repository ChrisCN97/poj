#include <iostream>
using namespace std;

/* input:
1.00
3.71
0.04
5.19
0.00
*/

/* output:
3 card(s)
61 card(s)
1 card(s)
273 card(s)
*/

// card lengths: 1/2 + 1/3 + 1/4 + ... + 1/(n + 1)

int main() {
	double reqLen, len;
	int n;
	while (cin >> reqLen) {
		if (reqLen == 0.00) break;
		n = 1;
		len = 0;
		while (true) {
			len += 1.0 / (n + 1);
			if (len >= reqLen) {
				cout << n << " card(s)" << endl;
				break;
			}
			n++;
		}
	}

	return 0;
}
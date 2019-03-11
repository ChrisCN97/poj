// poj 1018
// 2019.3.11

/* input:
1 3
3 100 25 150 35 80 25
2 120 80 155 40
2 100 100 120 110
*/

/* output:
0.649
*/

// By overall bandwidth (B) we mean the minimum of the bandwidths of the chosen devices
// the total price (P) is the sum of the prices of all chosen devices
// choose a manufacturer for each device to maximize B/P

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int caseNum, device, manu;
	double B, P, rate = 0, tb, tp, tr, b, p;

	cin >> caseNum >> device;
	while (caseNum--) {
		B = 0;
		P = 0;
		while (device--) {
			cin >> manu;
			rate = 0;
			while (manu--) {
				cin >> tb >> tp;
				tr = tb / tp;
				if (rate < tr) {
					rate = tr;
					b = tb;
					p = tp;
				}
			}
			B += b;
			P += p;
		}
		cout << setiosflags(ios::fixed) << setprecision(3) << B / P << endl;
	}

	return 0;
}
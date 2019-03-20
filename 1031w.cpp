// poj 1031
// 2019.3.19

/* input:
0.5 1.7 3
1.0 3.0
2.0 -1.0
-4.0 -1.0

0.5 1.7 6
0.0 1.0
-0.5 0.5
0.0 -1.0
-1.0 -0.5
0.0 -2.0
2.0 0

0.5 1.7 6
0.0 1.0
1.0 0.0
0.0 -1.0
-1.0 0.0
0.0 -2.0
2.0 0
*/

/* output:
5.34
*/

// I = k * h * (a1 - a2)

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double Pi = 3.14159265;

int main() {
	int N, i;
	double k, h, r, pa, na, da, x, y, fa;
	bool ifN;
	cin >> k >> h >> N;
	cin >> x >> y;
	r = sqrt(x*x + y * y);
	if (y >= 0) pa = acos(x / r);
	else pa = 2 * Pi- acos(x / r);
	fa = pa;
	int count = 0;
	while (true) {
		if (count == N) {
			da = 0;
			break;
		}
		cin >> x >> y;
		count++;
		r = sqrt(x*x + y * y);
		if (y >= 0) na = acos(x / r);
		else na = 2 * Pi - acos(x / r);
		if (na == pa) {
			continue;
		}
		if (abs(na - pa) > Pi) {
			if (na - pa > 0) ifN = false;
			else ifN = true;
			da = 2 * Pi - abs(na - pa);
		}
		else {
			if (na - pa > 0) ifN = true;
			else ifN = false;
			da = abs(na - pa);
		}
		pa = na;
		break;
	}
	
	for (i = 0; i < N-count-1; i++) {
		cin >> x >> y;
		r = sqrt(x*x + y * y);
		if (y >= 0) na = acos(x / r);
		else na = 2 * Pi - acos(x / r);
		if (abs(na - pa) < Pi) {
			if (ifN) {
				if (na > pa) 
					da += na - pa;
			}
			else {
				if (na < pa)
					da += pa - na;
			}
		}
		else {
			if (ifN) {
				if (na < pa)
					da += 2 * Pi - (pa - na);
			}
			else {
				if (na > pa)
					da += 2 * Pi - (na - pa);
			}
		}
		pa = na;
		if (da >= 2 * Pi)
			break;
	}

	if (da < 2 * Pi) {
		if (abs(fa - pa) < Pi) {
			if (ifN) {
				if (fa > pa)
					da += fa - pa;
			}
			else {
				if (fa < pa)
					da += pa - fa;
			}
		}
		else {
			if (ifN) {
				if (fa < pa)
					da += 2 * Pi - (pa - fa);
			}
			else {
				if (fa > pa)
					da += 2 * Pi - (fa - pa);
			}
		}
	}
	
	da = da >= 2 * Pi ? 2 * Pi : da;
	
	cout << setiosflags(ios::fixed) << setprecision(2) << k * h* da << endl;

	return 0;
}
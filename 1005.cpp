// poj 1005
// 2019.3.2

/* input:
2
1.0 1.0
25.0 0.0
*/

/* output:
Property 1: This property will begin eroding in year 1.
Property 2: This property will begin eroding in year 20.
END OF OUTPUT.
*/

// shrinking by 50 square miles each year
// area of semicircle: pi*r*r/2
// cal r
// cal len using (x, y)
// comp r and len

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	const double PI = 3.14159265;
	const double Shrink = 50;
	int N;
	double x, y, r, area, len;
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> x >> y;
		area = 0;
		for (int m = 1;; m++) {
			area += Shrink;
			r = sqrt(area * 2 / PI);
			len = sqrt(x * x + y * y);
			if (len <= r) {
				cout << "Property " << n << ": This property will begin eroding in year " << m << "." << endl;
				break;
			}
		}
	}
	cout << "END OF OUTPUT." << endl;

	return 0;
}
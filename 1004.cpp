// poj 1004
// 2019.3.2

/* input:
100.00
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75
*/

/* output:
$1581.42
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double sum = 0, month, ave;
	for (int n = 0; n < 12; n++) {
		cin >> month;
		sum += month;
	}
	ave = sum / 12;

	cout << setiosflags(ios::fixed) << setprecision(2) << "$" << ave << endl;

	return 0;
}
// poj 1018
// 2019.3.11

/* input:
2
3
3 100 25 150 35 80 25
2 120 80 155 40
2 100 100 120 110
2
1 150 55
2 110 80 135 40

*/

/* output:
0.649
*/

// By overall bandwidth (B) we mean the minimum of the bandwidths of the chosen devices
// the total price (P) is the sum of the prices of all chosen devices
// choose a manufacturer for each device to maximize B/P

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int caseNum, e, device, manu, i, b, p, temp;
	double result, tr;

	cin >> caseNum;
	while (caseNum--) {
		cin >> device;
		int **dp = new int*[device];
		for (i = 0; i < device; i++) {
			dp[i] = new int[400];
			for (int n = 0; n < 400; n++) dp[i][n] = INT_MAX;
		}
		for (e = 0; e < device; e++) {
			cin >> manu;
			while (manu--) {
				cin >> b >> p;
				if (e == 0) dp[e][b] = min(dp[e][b], p);
				else {
					for (i = 0; i < 400; i++) {
						if (dp[e - 1][i] < INT_MAX) {
							temp = min(i, b);
							dp[e][temp] = min(dp[e][temp], dp[e - 1][i] + p);
						}
					}
				}
			}
		}
		result = 0;
		for (i = 0; i < 400; i++) {
			if (dp[device - 1][i] < INT_MAX) {
				temp = dp[device - 1][i];
				tr = double(i) / double(temp);
				result = max(result, tr);
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(3) << result << endl;
		delete dp;
	}

	return 0;
}
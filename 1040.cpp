// poj 1040
// 2019.4.26

/* input:
10 3 4
0 2 1
1 3 5
1 2 7
2 3 10
10 5 4
3 5 10
2 4 9
0 2 5
2 5 8
10 7 22
0 1 1
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
0 1 1
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
0 1 1
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
0 1 1
0 0 0
*/

/* output:
19
34
*/

// In one block there can be maximum 22 orders. The number of the city B station will be at most 7

#include <iostream>
using namespace std;

int people, station, order, orders[22][3], stations[8];

int dfs(int begin) {
	int max = 0, b;
	for (int n = begin; n < order; n++) {
		for (b = orders[n][0] + 1; b <= orders[n][1]; b++) {
			if (stations[b] + orders[n][2] <= people)
				stations[b] += orders[n][2];
			else {
				for (int e = b - 1; e > orders[n][0]; e--)
					stations[e] -= orders[n][2];
				break;
			}
		}
		if (b == orders[n][1] + 1) {
			int temp = dfs(n + 1) + orders[n][2] * (orders[n][1] - orders[n][0]);
			if (max < temp) {
				max = temp;
			}
			for (int e = b - 1; e > orders[n][0]; e--)
				stations[e] -= orders[n][2];
		}
	}
	return max;
}

int main() {
	while (true) {
		cin >> people >> station >> order;
		if (people + station + order == 0)
			break;
		for (int n = 0; n < order; n++) {
			cin >> orders[n][0] >> orders[n][1] >> orders[n][2];
		}
		for (int n = 0; n <= station; n++)
			stations[n] = 0;

		cout << dfs(0) << endl;
	}

	return 0;
}
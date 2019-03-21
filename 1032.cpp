// poj 1032
// 2019.3.20

/* input:
7
*/

/* output:
3 4
*/

// N (5<=N<=1000 )
// disjoint groups of different sizes

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int i = 2, sum=0, left;
	vector<int> list;
	while (true) {
		sum += i;
		if (sum > N) {
			sum -= i;
			left = N - sum;
			break;
		}
		list.push_back(i);
		if (sum == N) {
			left = 0;
			break;
		}
		i++;
	}
	while (left > 0) {
		for (i = list.size() - 1; i >= 0; i--) {
			list[i]++;
			if (--left == 0) break;
		}
	}
	for (i = 0; i < list.size() - 1; i++)
		cout << list[i] << " ";
	cout << list.back() << endl;

	return 0;
}
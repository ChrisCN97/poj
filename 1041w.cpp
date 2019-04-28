// poj 1041
// 2019.4.27

/* input:
1 1 1
0 0
1 2 1
2 2 2
2 1 3
0 0
1 2 1
2 3 2
3 1 6
1 2 5
2 3 3
3 1 4
0 0
1 2 1
2 3 2
1 3 3
2 4 4
0 0
1 2 1
2 3 2
3 1 6
1 2 5
2 3 3
3 1 4
1 2 7
2 3 8
3 1 12
1 2 11
2 3 9
3 1 10
0 0
2 1 1
2 3 2
0 0
0 0
*/

/* output:
1 2 3 5 4 6
Round trip does not exist.
*/

// 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxe = 2018;

int map[60][maxe];
int route[maxe][2], rTime, rNum, rBegin;
bool check[maxe];
vector<int> result;

void fillRoute(int p, int r) {
	for (int n = 0; n < maxe; n++) {
		if (map[p][n] == 0) {
			map[p][n] = r;
			return;
		}
	}
}

int countRoute(int p) {
	for (int n = 0; n < maxe; n++) {
		if (map[p][n] == 0)
			return n;
	}
}

void dfs(int p, int r) {
	for (int n = 0; n < countRoute(p); n++) {
		if (check[map[p][n]])
			continue;
		check[map[p][n]] = true;
		int another;
		if (route[map[p][n]][0] == p)
			another = route[map[p][n]][1];
		else
			another = route[map[p][n]][0];

		dfs(another, map[p][n]);
	}
	result.push_back(r);
}

int main() {
	int p1, p2, r;
	while (true) {
		cin >> p1 >> p2;
		if (p1 + p2 == 0)
			break;
		cin >> r;
		for (int m = 0; m < 60; m++) {
			for (int n = 0; n < maxe; n++) {
				map[m][n] = 0;
			}
		}
		for (int m = 0; m < maxe; m++) {
			check[m] = false;
			for (int n = 0; n < 2; n++) {
				route[m][n] = 0;
			}
		}
		fillRoute(p1, r);
		fillRoute(p2, r);
		route[r][0] = p1;
		route[r][1] = p2;
		rBegin = p1 < p2 ? p1 : p2;
		rNum = 1;
		result.clear();
		while (true) {
			cin >> p1 >> p2;
			if (p1 + p2 == 0)
				break;
			cin >> r;
			fillRoute(p1, r);
			fillRoute(p2, r);
			route[r][0] = p1;
			route[r][1] = p2;
			rNum++;
		}
		int nIn;
		for (nIn = 0; nIn < 60; nIn++) {
			if (map[nIn][0] != 0) {
				if (countRoute(nIn) % 2 != 0)
					break;
				sort(map[nIn], map[nIn] + countRoute(nIn));
			}
		}
		if (nIn != 60) {
			cout << "Round trip does not exist." << endl;
			continue;
		}
		rTime = 0;
		dfs(rBegin, 0);
		for (int n = rNum - 1; n > 0; n--) {
			cout << result[n] << " ";
		}
		cout << result[0];
		cout << endl;
		
	}

	return 0;
}
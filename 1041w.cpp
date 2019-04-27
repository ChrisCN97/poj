// poj 1041
// 2019.4.27

/* input:
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

int map[45][45];
int route[1996][2], rTime, rNum, rBegin;
bool check[1996];
vector<int> result;

void fillRoute(int p, int r) {
	for (int n = 0; n < 45; n++) {
		if (map[p][n] == 0) {
			map[p][n] = r;
			return;
		}
	}
}

int countRoute(int p) {
	for (int n = 0; n < 45; n++) {
		if (map[p][n] == 0)
			return n;
	}
}

bool dfs(int p) {
	for (int n = 0; n < countRoute(p); n++) {
		if (check[map[p][n]])
			continue;
		check[map[p][n]] = true;
		result.push_back(map[p][n]);
		rTime++;
		int another;
		if (route[map[p][n]][0] == p)
			another = route[map[p][n]][1];
		else
			another = route[map[p][n]][0];
		if (rTime == rNum) {
			if (another == rBegin)
				return true;
			else {
				result.pop_back();
				check[map[p][n]] = false;
				rTime--;
				continue;
			}
		}
		
		if (dfs(another))
			return true;
		else {
			result.pop_back();
			check[map[p][n]] = false;
			rTime--;
		}
	}
	return false;
}

int main() {
	int p1, p2, r;
	while (true) {
		cin >> p1 >> p2;
		if (p1 + p2 == 0)
			break;
		cin >> r;
		for (int m = 0; m < 45; m++) {
			for (int n = 0; n < 45; n++) {
				map[m][n] = 0;
			}
		}
		for (int m = 0; m < 1996; m++) {
			check[m] = false;
			for (int n = 0; n < 2; n++) {
				route[m][n] = 0;
			}
		}
		map[p1][0] = r;
		map[p2][0] = r;
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
		for (int n = 0; n < 45; n++) {
			if (map[n][0] != 0) {
				sort(map[n], map[n] + countRoute(n));
			}
		}
		rTime = 0;
		if (dfs(rBegin)) {
			for (int n = 0; n < rNum; n++) {
				cout << result[n] << " ";
			}
			cout << endl;
		}
		else {
			cout << "Round trip does not exist." << endl;
		}
	}
	
	return 0;
}
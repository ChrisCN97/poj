// poj 1021
// 2019.3.14

/* input:
6
8 6 19
0 1 1 2 1 1 1 0 2 5 2 1 3 5 3 4 4 5 4 4 4 3 5 5 5 4 6 5 4 0 5 1 5 0 6 2 6 1
2 5 2 4 2 3 2 2 2 1 1 4 1 3 1 2 0 3 4 2 5 4 5 2 5 1 6 5 6 4 6 3 6 1 6 0 7 4
9 6 18
0 4 1 4 1 3 1 2 2 3 2 2 4 2 5 0 5 1 5 2 5 3 6 2 7 3 7 1 8 4 8 3 8 2 8 1
0 4 0 0 1 4 1 1 1 0 2 5 2 4 2 3 2 1 3 0 3 1 3 4 5 2 6 2 6 3 6 4 7 3 7 4
9 6 18
0 5 1 5 1 4 1 3 2 4 2 3 3 2 4 3 4 2 4 1 4 0 5 2 7 3 7 4 7 2 8 5 8 2 8 4
0 4 0 0 1 4 1 1 1 0 2 5 2 4 2 3 2 1 3 0 3 1 3 4 5 2 6 2 6 3 6 4 7 3 7 4
7 9 27
0 6 0 5 0 4 1 1 1 6 2 1 2 2 2 3 2 4 2 5 2 6 2 7 2 8 3 3 3 4 3 6 3 8 4 3 5 0 5 1 5 2 5 3 5 4 5 5 5 6 6 3 6 5
0 3 0 5 1 2 1 3 1 4 1 5 1 6 1 7 1 8 2 5 3 0 3 2 3 4 3 5 4 0 4 1 4 2 4 3 4 4 4 5 4 6 4 7 5 2 5 7 6 2 6 3 6 4
6 3 14
0 0 0 1 0 2 1 1 2 0 2 1 2 2 3 1 3 2 3 0 4 1 4 2 5 0 5 1
0 1 0 2 1 1 1 2 1 0 2 0 2 1 3 2 3 1 3 0 4 1 5 0 5 1 5 2
6 3 14
0 0 0 1 0 2 1 1 2 0 2 1 2 2 3 1 3 2 4 0 4 1 4 2 5 0 5 1
0 1 0 2 1 1 1 2 1 0 2 0 2 1 3 2 3 1 3 0 4 1 5 0 5 1 5 2
*/

/* output:
YES
NO
YES
YES
NO
YES
*/

// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int w, h;

struct Point {
	int x;
	int y;
	Point(int X, int Y) {
		x = X;
		y = Y;
	}
};

bool setPoint(int **map, int x, int y, vector<Point> &set) {
	if (map[x][y] != 1) return false;
	set.push_back(Point(x, y));
	map[x][y] = 2;

	if (x > 0) setPoint(map, x - 1, y, set);
	if (x < w - 1) setPoint(map, x + 1, y, set);
	if (y > 0) setPoint(map, x, y - 1, set);
	if (y < h - 1) setPoint(map, x, y + 1, set);
	return true;
}

double calKey(vector<Point> &set) {
	double result=0;
	int x1, y1, x2, y2;
	for (int m = 0; m < set.size()-1; m++) {
		for (int n = m + 1; n < set.size(); n++) {
			x1 = set[m].x;
			y1 = set[m].y;
			x2 = set[n].x;
			y2 = set[n].y;
			result += pow(x1 - x2, 2) + pow(y1 - y2, 2);
		}
	}
	return result;
}

int main() {
	int caseNum, pNum, i, x, y, n, **map1, **map2;
	cin >> caseNum;
	while (caseNum--) {
		cin >> w >> h >> pNum;
		map1 = new int*[w];
		map2 = new int*[w];
		for (i = 0; i < w; i++) {
			map1[i] = new int[h];
			map2[i] = new int[h];
			for (n = 0; n < h; n++) {
				map1[i][n] = 0;
				map2[i][n] = 0;
			} 
		} 
		for (i = 0; i < pNum; i++) {
			cin >> x >> y;
			map1[x][y] = 1;
		}
		for (i = 0; i < pNum; i++) {
			cin >> x >> y;
			map2[x][y] = 1;
		}

		vector<double> key1, key2;
		vector<Point> set;
		key1.clear();
		key2.clear();
		for (y = 0; y < h; y++) {
			for (x = 0; x < w; x++) {
				set.clear();
				if(setPoint(map1, x, y, set)) key1.push_back(calKey(set));
			}
		}
		for (y = 0; y < h; y++) {
			for (x = 0; x < w; x++) {
				set.clear();
				if(setPoint(map2, x, y, set)) key2.push_back(calKey(set));
			}
		}

		sort(key1.begin(), key1.end());
		sort(key2.begin(), key2.end());

		if (key1 == key2) cout << "YES" << endl;
		else cout << "NO" << endl;

		delete map1;
		delete map2;
	}

	return 0;
}
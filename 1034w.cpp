// poj 1034
// 2019.4.14

/* input:
4 5
1 4 5 7 5 2 -2 4
-4 -2 3 9 1 2 -1 3 8 -3
2 0
1 4 2 4

2 1
-1000 -1000 1000 1000
0 1000
*/

/* output:
6
1 4 3 9 5 7 5 2 1 2 -2 4
*/

// 
#include <iostream>
#include <math.h>
using namespace std;

struct Point {
	int x;
	int y;
};

int mNum, iNum, m2i[100], i2m[100];
Point mRoute[100];
Point iRoute[100];
bool arrive[100][100];

bool change(int m) {
	for (int i = 0; i < iNum; i++) {
		if (arrive[m][i]) {
			if (i2m[i] == -1) {
				m2i[m] = i;
				i2m[i] = m;
				return true;
			}
			int pm = i2m[i];
			m2i[m] = i;
			i2m[i] = m;
			m2i[pm] = -1;
			if (change(pm)) {
				return true;
			}
			m2i[pm] = i;
			m2i[m] = -1;
			i2m[i] = pm;
		}
	}
	return false;
}

int main() {
	int maxInters = 0;
	cin >> mNum >> iNum;
	for (int i = 0; i < mNum; i++) {
		cin >> mRoute[i].x >> mRoute[i].y;
	}
	if (iNum != 0) {
		memset(i2m, 0, sizeof(i2m));
		memset(m2i, 0, sizeof(m2i));
		for (int i = 0; i < iNum; i++) {
			cin >> iRoute[i].x >> iRoute[i].y;
			i2m[i] = -1;
		}
		for (int i = 0; i < mNum; i++) {
			for (int n = 0; n < iNum; n++) {
				arrive[i][n] = false;
			}
			m2i[i] = -1;
		}
		memset(arrive, false, sizeof(arrive));
		for (int i = 1; i < mNum; i++) {
			double mLen = sqrt(double((mRoute[i].x - mRoute[i - 1].x)*(mRoute[i].x - mRoute[i - 1].x)) + double((mRoute[i].y - mRoute[i - 1].y)*(mRoute[i].y - mRoute[i - 1].y)));
			for (int n = 0; n < iNum; n++) {
				double L1 = sqrt(double((iRoute[n].x - mRoute[i - 1].x)*(iRoute[n].x - mRoute[i - 1].x)) + double((iRoute[n].y - mRoute[i - 1].y)*(iRoute[n].y - mRoute[i - 1].y)));
				double L2 = sqrt(double((iRoute[n].x - mRoute[i].x)*(iRoute[n].x - mRoute[i].x)) + double((iRoute[n].y - mRoute[i].y)*(iRoute[n].y - mRoute[i].y)));
				if (L1 + L2 <= 2 * mLen) {
					arrive[i][n] = true;
				}
			}
		}
		for (int i = 1; i < mNum; i++) {
			if (change(i)) {
				maxInters++;
			}
		}
	}
	cout << maxInters + mNum << endl;
	cout << mRoute[0].x << " " << mRoute[0].y << " ";
	for (int i = 1; i < mNum; i++) {
		if (iNum != 0 && m2i[i] != -1)
			cout << iRoute[m2i[i]].x << " " << iRoute[m2i[i]].y << " ";
		cout << mRoute[i].x << " " << mRoute[i].y;
		if (i == mNum - 1) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}

	return 0;
}
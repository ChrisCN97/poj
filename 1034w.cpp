// poj 1034
// 2019.4.7

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
#include <cmath>
#include <vector>
using namespace std;

struct mPoint {
	int x;
	int y;
	vector<int> iPList;
	int i;
};

struct iPoint {
	int x;
	int y;
	int m;
};

int mNum, iNum;
mPoint *mRoute;
iPoint *iRoute;

bool change(int m) {
	for (int i = mRoute[m].iPList.size() - 1; i >= 0; i--) {
		int ins = mRoute[m].iPList[i];
		if (iRoute[ins].m == 0) {
			mRoute[m].i = ins;
			iRoute[ins].m = m;
			return true;
		}
		int pIRM = iRoute[ins].m;
		mRoute[m].i = ins;
		mRoute[pIRM].i = -1;
		iRoute[ins].m = m;
		if (change(pIRM)) {
			return true;
		}
		iRoute[ins].m = pIRM;
		mRoute[pIRM].i = ins;
		mRoute[m].i = -1;
	}
	return false;
}

int main() {
	int i, n, x, y, maxInters = 0;
	cin >> mNum >> iNum;
	mRoute = new mPoint[mNum];
	if (iNum == 0) {
		for (i = 0; i < mNum; i++) {
			cin >> x >> y;
			mPoint m;
			m.x = x;
			m.y = y;
			mRoute[i] = m;
		}
	}
	else {
		iRoute = new iPoint[iNum];
		for (i = 0; i < mNum; i++) {
			cin >> x >> y;
			mPoint m;
			m.x = x;
			m.y = y;
			m.i = -1;
			mRoute[i] = m;
		}
		for (i = 0; i < iNum; i++) {
			cin >> x >> y;
			iPoint m;
			m.x = x;
			m.y = y;
			m.m = 0;
			iRoute[i] = m;
		}

		double mLen, L1, L2;
		for (i = 1; i < mNum; i++) {
			mLen = sqrt(pow(mRoute[i].x - mRoute[i - 1].x, 2) + pow(mRoute[i].y - mRoute[i - 1].y, 2));
			for (n = 0; n < iNum; n++) {
				L1 = sqrt(pow(iRoute[n].x - mRoute[i - 1].x, 2) + pow(iRoute[n].y - mRoute[i - 1].y, 2));
				L2 = sqrt(pow(iRoute[n].x - mRoute[i].x, 2) + pow(iRoute[n].y - mRoute[i].y, 2));
				if (L1 + L2 <= 2 * mLen) {
					mRoute[i].iPList.push_back(n);
				}
			}
		}
		for (i = 1; i < mNum; i++) {
			for (n = 0; n < mRoute[i].iPList.size(); n++) {
				int ins = mRoute[i].iPList[n];
				if (iRoute[ins].m == 0) {
					mRoute[i].i = ins;
					iRoute[ins].m = i;
					maxInters++;
					break;
				}
			}
		}

		if (maxInters != mNum - 1) {
			for (i = 1; i < mNum; i++) {
				if (mRoute[i].i == -1) {
					if (change(i)) {
						maxInters++;
					}
				}
			}
		}
	}
	cout << maxInters + mNum << endl;
	cout << mRoute[0].x << " " << mRoute[0].y << " ";
	for (i = 1; i < mNum; i++) {
		if (iNum != 0 && mRoute[i].i != -1)
			cout << iRoute[mRoute[i].i].x << " " << iRoute[mRoute[i].i].y << " ";
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
// poj 1034
// 2019.3.21

/* input:
4 5
1 4 5 7 5 2 -2 4
-4 -2 3 9 1 2 -1 3 8 -3
*/

/* output:
6
1 4 3 9 5 7 5 2 1 2 -2 4
*/

// possibly self-intersecting
// Ralph can travel at a speed that is up to two times greater than his master's speed.
// the dog visits at most one interesting place before meeting his master again
// The latter should be visited (i.e. listed in the route description) at most once
// If there are several such routes, then you may write any of them.

#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	int x;
	int y;
	bool check;
};

Point *mRoute, *iRoute;
int master, inters, *ans;
double **ilen, *mlen;

int dfs(int n) {
	int i, pmax = 0, pcount = 0;
	Point a, b;
	bool flag = false;
	a = mRoute[n - 1];
	b = mRoute[n];
	for (i = 0; i < inters; i++) {
		if (ilen[n][i] == 0) {
			Point c = iRoute[i];
			ilen[n][i] = sqrt(pow(c.x - a.x, 2) + pow(c.y - a.y, 2)) + sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
		}
		if (mlen[n] == 0) {
			mlen[n] = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
		}
		if (n == 1) {
			for(int x=0; x<inters; x++)
				iRoute[x].check = false;
		}	
		if (!iRoute[i].check && ilen[n][i] <= 2 * mlen[n]) {
			iRoute[i].check = true;
			if (n == master - 1) {
				ans[n] = i;
				return 1;
			} 
			pcount = dfs(n + 1);
			if (pmax < pcount) {
				pmax = pcount;
				ans[n] = i;
				if (!flag) flag = true;
			}
		}
	}
	if (n == master - 1) return 0;
	if (!flag) return dfs(n + 1);
	return pmax + 1;
}

int main() {
	int i, x, y;
	cin >> master >> inters;
	mRoute = new Point[master];
	iRoute = new Point[inters];
	ilen = new double*[master];
	mlen = new double[master];
	ans = new int[master];
	for (i = 0; i < master; i++) {
		cin >> x >> y;
		Point p;
		p.x = x;
		p.y = y;
		mRoute[i] = p;
		ilen[i] = new double[inters];
		for (int n = 0; n < inters; n++) 
			ilen[i][n] = 0;
		mlen[i] = 0;
		ans[i] = -1;
	}
	for (i = 0; i < inters; i++) {
		cin >> x >> y;
		Point p;
		p.x = x;
		p.y = y;
		p.check = false;
		iRoute[i] = p;
	}
	int max = dfs(1);
	cout << max + master << endl;
	cout << mRoute[0].x << " " << mRoute[0].y;
	for (i = 1; i < master; i++) {
		if (ans[i] != -1)
			cout << " " << iRoute[ans[i]].x << " " << iRoute[ans[i]].y;
		cout << " " << mRoute[i].x << " " << mRoute[i].y;
	}
	cout << endl;

	return 0;
}
// poj 1038
// 2019.4.18

/* input:
4
6 6 5
1 4
4 6
2 2
3 6
6 4
6 5 4
3 3
6 1
6 2
6 4
6 6 0
150 10 0
*/

/* output:
3
4
6
*/

// The corporation wants to waste as little good squares as possible.
// make the maximum number of chips possible

#include <iostream>
using namespace std;

bool map[151][11];
int X, Y, bug;

bool fill23(int x, int y) {
	if (x >= X - 1 || y == Y)
		return false;
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 2; n++) {
			if (!map[x + m][y + n])
				return false;
		}
	}
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 2; n++) {
			map[x + m][y + n] = false;
		}
	}
	return true;
}

void re23(int x, int y) {
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 2; n++) {
			map[x + m][y + n] = true;
		}
	}
}

bool fill32(int x, int y) {
	if (x == X || y >= Y - 1)
		return false;
	for (int m = 0; m < 2; m++) {
		for (int n = 0; n < 3; n++) {
			if (!map[x + m][y + n])
				return false;
		}
	}
	for (int m = 0; m < 2; m++) {
		for (int n = 0; n < 3; n++) {
			map[x + m][y + n] = false;
		}
	}
	return true;
}

void re32(int x, int y) {
	for (int m = 0; m < 2; m++) {
		for (int n = 0; n < 3; n++) {
			map[x + m][y + n] = true;
		}
	}
}

int dfs(int x, int y) {
	int result = -1, xB = 0, xB2 = 0, xR, yR;
	bool flag23 = false, flag32 = false, is23 = false, is32 = false;
	while (true) {
		if (x > X) {
			x = 1;
			y++;
		}
		if ((y == Y - 1 && x > X - 2) || y >= Y) {
			break;
		}
		if (flag23 && flag32 && x >= xB + 3 && x >= xB2 + 2) {
			break;
		}
		if (!map[x][y]) {
			x++;
			if (x > X) {
				x = 1;
				y++;
			}
			continue;
		}
		if (x < X - 1 && y < Y) {
			if (!flag23 || (flag23 && x < xB + 3)) {
				if (fill23(x, y)) {
					if (!flag23) {
						flag23 = true;
						xB = x;
					}
					int temp = dfs(x + 3, y);
					if (result < temp) {
						is23 = true;
						is32 = false;
						result = temp;
						xR = x;
						yR = y;
					}
					re23(x, y);
				}
			}
		}
		
		if (x < X && y < Y - 1) {
			if (!flag32 || (flag32 && x < xB2 + 2)) {
				if (fill32(x, y)) {
					if (!flag32) {
						flag32 = true;
						xB2 = x;
					}
					int temp = dfs(x + 2, y);
					if (result < temp) {
						is23 = false;
						is32 = true;
						result = temp;
						xR = x;
						yR = y;
					}
					re32(x, y);
				}
			}
		}
		x++;
		if (x > X) {
			x = 1;
			y++;
		}
	}
	return result + 1;
}

int main() {
	int x, y, caseNum;
	cin >> caseNum;
	while (caseNum--) {
		cin >> X >> Y >> bug;
		for (x = 0; x < 151; x++) {
			for (y = 0; y < 11; y++) {
				map[x][y] = true;
			}
		}
		while (bug--) {
			cin >> x >> y;
			map[x][y] = false;
		}
		cout << dfs(1, 1) << endl;
	}
	
	return 0;
}
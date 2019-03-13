// poj 1020
// 2019.3.13

/* input:
13
4 8 1 1 1 1 1 3 1 1
5 6 3 3 2 1 1 1
10 14 1 1 1 1 1 4 4 3 3 3 3 3 3 3
*/

/* output:
KHOOOOB!
HUTUTU!
KHOOOOB!
*/

// 

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

bool dfs(int *pArr, bool **cArr, bool *set, int piece, int cake) {
	int temp, i, m, n, m2, n2, tm, tn, tt, ti;
	bool flag, flag2;

	for (i = 0; i < piece; i++) {
		if (!set[i]) break;
	}
	if (i == piece) return true;
	for (i = 0; i < piece; i++) {
		if (set[i]) continue;
		else set[i] = true;
		temp = pArr[i];
		flag = false;
		for (m = 0; m < cake; m++) {
			for (n = 0; n < cake; n++) {
				if (!cArr[m][n]) {
					if (n + temp > cake || m + temp > cake) break;
					flag2 = true;
					for (m2 = 0; m2 < temp; m2++) {
						for (n2 = 0; n2 < temp; n2++) {
							if (cArr[m + m2][n + n2]) {
								flag2 = false;
								break;
							}
						}
						if (!flag2) break;
					}
					if (!flag2) continue;
					for (m2 = 0; m2 < temp; m2++) {
						for (n2 = 0; n2 < temp; n2++) {
							cArr[m + m2][n + n2] = true;
						}
					}
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) {
			set[i] = false;
			continue;
		} 
		if (dfs(pArr, cArr, set, piece, cake)) return true;
		for (m2 = 0; m2 < temp; m2++) {
			for (n2 = 0; n2 < temp; n2++) {
				cArr[m + m2][n + n2] = false;
			}
		}
		set[i] = false;
	}
	return false;
}

int main() {
	int caseNum, cake, piece, *pArr, area, i, temp;
	bool **cArr, *set;

	cin >> caseNum;
	while (caseNum--) {
		cin >> cake >> piece;
		pArr = new int[piece];
		set = new bool[piece];
		area = 0;
		for (i = 0; i < piece; i++) {
			cin >> temp;
			pArr[i] = temp;
			set[i] = false;
			area += temp * temp;
		}
		if (area != cake*cake) {
			cout << "HUTUTU!" << endl;
			continue;
		}
		sort(pArr, pArr + piece, compare);
		cArr = new bool*[cake];
		for (i = 0; i < cake; i++) cArr[i] = new bool[cake];
		for (int m = 0; m < cake; m++) {
			for (int n = 0; n < cake; n++) {
				cArr[m][n] = false;
			}
		}
		if (dfs(pArr, cArr, set, piece, cake)) cout << "KHOOOOB!" << endl;
		else cout << "HUTUTU!" << endl;

		delete pArr;
		delete cArr;
	}

	return 0;
}
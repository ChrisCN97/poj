// poj 1022
// 2019.3.14

/* input:
1
9
66 0 0 0 1 0 0 0 0
1 2 3 66 5 6 7 8 9
2 0 1 0 0 0 0 0 0
3 1 0 0 0 0 0 0 0
5 0 0 1 0 0 0 0 0
6 0 0 0 0 0 1 0 0
7 0 0 0 0 1 0 0 0
8 0 0 0 0 0 0 0 1
9 0 0 0 0 0 0 1 0
*/

/* output:
81
*/

// Inconsistent
// 

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Cube {
	int id;
	int d[4][3];
};

Cube *cubeSet;
int cubeNum;

bool dfs(int id, int d, int &len, int dir, int form) {
	int i;
	for (i = 0; i < cubeNum; i++) {
		if (cubeSet[i].id == id)
			break;
	}
	if (form != 0 && cubeSet[i].d[d][abs(dir - 1)] != form) return false;
	if (cubeSet[i].d[d][2] != 1 && cubeSet[i].d[d][dir] != 0) {
		len++;
		cubeSet[i].d[d][2] = 1;
		if(!dfs(cubeSet[i].d[d][dir], d, len, dir, id))
			return false;
	}
	return true;
}

int main() {
	int caseNum;
	cin >> caseNum;
	while (caseNum--) {
		cin >> cubeNum;
		cubeSet = new Cube[cubeNum];
		for (int i = 0; i < cubeNum; i++) {
			int id, d10, d11, d20, d21, d30, d31, d40, d41;
			cin >> id >> d10 >> d11 >> d20 >> d21 >> d30 >> d31 >> d40 >> d41;
			cubeSet[i].id = id;
			cubeSet[i].d[0][0] = d10;
			cubeSet[i].d[0][1] = d11;
			cubeSet[i].d[0][2] = 0;
			cubeSet[i].d[1][0] = d20;
			cubeSet[i].d[1][1] = d21;
			cubeSet[i].d[1][2] = 0;
			cubeSet[i].d[2][0] = d30;
			cubeSet[i].d[2][1] = d31;
			cubeSet[i].d[2][2] = 0;
			cubeSet[i].d[3][0] = d40;
			cubeSet[i].d[3][1] = d41;
			cubeSet[i].d[3][2] = 0;
		}
		int len[4] = { 0 };
		for (int i = 0; i < cubeNum; i++) {
			for (int d = 0; i < 4; i++) {
				for (int dir = 0; dir < 2; dir++) {
					if (!dfs(cubeSet[i].id, d, len[d], dir, 0)) {
						cout << "Inconsistent" << endl;
						return 0;
					}
				}
			}
		}
		cout << len[0] * len[1] * len[2] * len[3] << endl;

		delete cubeSet;
	}

	return 0;
}
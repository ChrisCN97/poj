// poj 1022
// 2019.3.14

/* input:
3
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
2
3 0 0 1 0 0 0 0 0
1 0 0 3 0 0 0 0 0
4
1 2 0 0 0 0 0 0 0
2 0 1 0 0 0 0 0 0
3 0 0 4 0 0 0 0 0
4 0 0 0 3 0 0 0 0
*/

/* output:
81
*/

// Inconsistent
// 

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Cube {
	int id;
	int d[4][2];
	bool check;
};

Cube *cubeSet;
int cubeNum, len[4];
int countNode;

bool dfs(int id, int p, int d, int dir) {
	if (id == 0)
		return true;
	int i;
	for (i = 0; i < cubeNum; i++) {
		if (cubeSet[i].id == id)
			break;
	}
	if (p != 0 && cubeSet[i].d[d][abs(dir - 1)] != p)
		return false;
	if (cubeSet[i].check) return true;
	else {
		cubeSet[i].check = true;
		countNode++;
		if (p != 0) len[d]++;
	} 
	
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 2; m++) {
			if (!dfs(cubeSet[i].d[n][m], id, n, m))
				return false;
		}
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
			cubeSet[i].d[1][0] = d20;
			cubeSet[i].d[1][1] = d21;
			cubeSet[i].d[2][0] = d30;
			cubeSet[i].d[2][1] = d31;
			cubeSet[i].d[3][0] = d40;
			cubeSet[i].d[3][1] = d41;
			cubeSet[i].check = false;
		}
		for (int i = 0; i < 4; i++)
			len[i] = 1;
		countNode = 0;
		if (!dfs(cubeSet[0].id, 0, 0, 0) || countNode != cubeNum) {
			cout << "Inconsistent" << endl;
			delete cubeSet;
			continue;
		}
		
		cout << len[0] * len[1] * len[2] * len[3] << endl;

		delete cubeSet;
	}

	return 0;
}
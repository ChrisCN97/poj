// poj 1020
// 2019.3.13

/* input:
13
4 8 1 1 1 1 1 3 1 1
5 6 3 3 2 1 1 1
10 14 1 1 1 1 1 4 4 3 3 3 3 3 3 3
21 16 5 7 2 4 8 9 4 2 3 2 4 2 9 6 4 4
28 16 10 10 7 3 5 9 10 3 8 5 7 7 5 7 1 7
13 11 1 2 2 8 1 2 3 7 1 4 4
23 16 1 7 5 8 5 10 9 2 1 4 2 6 3 1 8 7
26 16 3 7 10 9 8 3 1 9 6 6 8 2 10 1 5 4
21 16 6 5 10 4 2 3 4 7 7 2 3 3 1 1 7 8
18 14 2 6 3 1 2 3 9 9 4 5 7 2 1 2
15 12 3 1 3 1 8 1 5 1 6 2 6 3
22 15 2 6 8 5 4 7 9 9 4 5 4 3 6 3 4
22 14 4 1 6 7 9 1 7 3 10 8 1 6 5 4
*/

/* output:

*/

// 

#include <iostream>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

bool dfs(int *size, int *map, int cake, int n, int piece) {
	int i, minColNum = map[0], minCol = 0, col;
	if (n == piece) return true;

	for (i = 1; i < cake; i++) {
		if (minColNum > map[i]) {
			minColNum = map[i];
			minCol = i;
		}
	}

	for (i = 10; i > 0; i--) {
		if (size[i] == 0) continue;
		int flag = false;
		if (i + minCol > cake || i + minColNum > cake) continue;
		for (col = minCol+1; col < minCol + i; col++) {
			if (map[col] > map[minCol]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;
		for (col = minCol; col < minCol + i; col++) {
			map[col] += i;
		}
		size[i]--;
		if(dfs(size, map, cake, n + 1, piece)) return true;
		size[i]++;
		for (col = minCol; col < minCol + i; col++) {
			map[col] -= i;
		}
	}
	return false;
}

int main() {
	int caseNum, cake, size[11], piece, temp, i, *map, area, half;

	cin >> caseNum;
	while (caseNum--) {
		cin >> cake >> piece;
		area = 0;
		half = 0;
		for (i = 0; i < 11; i++) size[i] = 0;
		map = new int[cake];
		for (i = 0; i < cake; i++) map[i] = 0;
		for (i = 0; i < piece; i++) {
			cin >> temp;
			size[temp]++;
			area += temp * temp;
			if (temp > cake / 2) half++;
		}
		if (half > 1 || area != cake * cake) {
			cout << "HUTUTU!" << endl;
			continue;
		} 
		if (dfs(size, map, cake, 0, piece)) cout << "KHOOOOB!" << endl;
		else cout << "HUTUTU!" << endl;
	}
	
	return 0;
}
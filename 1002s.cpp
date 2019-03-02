#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/* input:
12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279
*/

/* output:
310-1010 2
487-3279 4
888-4567 3
*/

// use hash list to reduce running time


int main() {
	int num, i, *iArr, pre, now, repeat = 1;
	string s;

	cin >> num;
	iArr = new int[12];
	//int iArr[12];
	if (num < 2) {
		cout << "No duplicates. " << endl;
	}

	for (i = 0; i < num; i++) {
		iArr[i] = 0;
		cin >> s;
		for (int n = 0; n < s.length(); n++) {
			if (s[n] >= '0' && s[n] <= '9') {
				iArr[i] *= 10;
				iArr[i] += s[n] - '0';
			}
			else if (s[n] >= 'A' && s[n] <= 'Z') {
				iArr[i] *= 10;
				switch (s[n]) {
				case 'A': case 'B': case 'C':
					iArr[i] += 2;
					break;
				case 'D': case 'E': case 'F':
					iArr[i] += 3;
					break;
				case 'G': case 'H': case 'I':
					iArr[i] += 4;
					break;
				case 'J': case 'K': case 'L':
					iArr[i] += 5;
					break;
				case 'M': case 'N': case 'O':
					iArr[i] += 6;
					break;
				case 'P': case 'R': case 'S':
					iArr[i] += 7;
					break;
				case 'T': case 'U': case 'V':
					iArr[i] += 8;
					break;
				case 'W': case 'X': case 'Y':
					iArr[i] += 9;
					break;
				}
			}
		}
	}

	sort(iArr, iArr + num);

	for (i = 1; i < num; i++) {
		pre = iArr[i - 1];
		now = iArr[i];
		if (pre == now) repeat++;
		else if (repeat > 1) {
			cout << pre / 10000 << '-' << pre % 10000 << ' ' << repeat << endl;
			repeat = 1;
		}
	}
	if (repeat > 1) {
		cout << pre / 10000 << '-' << pre % 10000 << ' ' << repeat << endl;
	}

	return 0;
}
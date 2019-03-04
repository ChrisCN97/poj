// poj 1007
// 2019.3.4

/* input:
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
*/

/* output:
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA
*/

#include <iostream>
using namespace std;

int main() {
	char **arr, *tempC;
	int *sortArr, p, tempI, len, num, m, n, tNum;

	cin >> len >> num;
	arr = new char *[num];
	sortArr = new int[num];
	for (m = 0; m < num; m++) arr[m] = new char[len + 1];
	for (m = 0; m < num; m++) {
		cin >> arr[m];
		sortArr[m] = 0;
		for (n = 0; n < len; n++) {
			if (arr[m][n] == 'A') continue;
			for (p = n+1; p < len; p++) {
				if (arr[m][n] > arr[m][p]) sortArr[m]++;
			}
		}
	}

	tNum = num;
	for (m = 0; m < tNum-1; tNum--) {
		for (p = 0; p < tNum-1; p++) {
			if (sortArr[p] > sortArr[p+1]) {
				tempI = sortArr[p]; sortArr[p] = sortArr[p + 1]; sortArr[p + 1] = tempI;
				tempC = arr[p]; arr[p] = arr[p + 1]; arr[p + 1] = tempC;
			}
		}
	}

	for (m = 0; m < num; m++) cout << arr[m] << endl;

	return 0;
}
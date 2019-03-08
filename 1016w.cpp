// poj 1016
// 2019.3.8

/* input:
22
31123314
314213241519
21221314
111222234459
-1
*/

/* output:
22 is self-inventorying 
31123314 is self-inventorying 
314213241519 enters an inventory loop of length 2 
21221314 is self-inventorying after 2 steps 
111222234459 enters an inventory loop of length 2 
*/

// di satisfy 0<=d1<d2<...<dk<=9
/*
n is self-inventorying 
n is self - inventorying after j steps
n enters an inventory loop of length k
n can not be classified after 15 iterations
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int caseNum, turn, i, isCoinLight[12], len, isCoinTrue[12], fake;
	string left, right, result;
	bool isCoinApp[12];
	char letter;
	cin >> caseNum;
	while (caseNum--) {
		for (i = 0; i < 12; i++) {
			isCoinTrue[i] = 0;
			isCoinLight[i] = 0;
			isCoinApp[i] = false;
		} 
		for (turn = 0; turn < 3; turn++) {
			cin >> left >> right >> result;
			len = left.size();
			for (i = 0; i < len; i++) {
				isCoinApp[left[i] - 'A'] = true;
				isCoinApp[right[i] - 'A'] = true;
			}
			if (result == "even") {
				for (i = 0; i < len; i++) {
					isCoinTrue[left[i] - 'A'] = 1;
					isCoinTrue[right[i] - 'A'] = 1;
				}
			}
			else if (result == "up") {
				for (i = 0; i < len; i++) {
					if (isCoinLight[left[i] - 'A'] == 1 || isCoinTrue[left[i] - 'A'] == 1) {
						isCoinTrue[left[i] - 'A'] = 1;
						isCoinLight[left[i] - 'A'] = 0;
					}
					else {
						isCoinLight[left[i] - 'A'] = -1;
						isCoinTrue[left[i] - 'A']--;
					} 
					if (isCoinLight[right[i] - 'A'] == -1 || isCoinTrue[right[i] - 'A'] == 1) {
						isCoinTrue[right[i] - 'A'] = 1;
						isCoinLight[right[i] - 'A'] = 0;
					}
					else {
						isCoinLight[right[i] - 'A'] = 1;
						isCoinTrue[right[i] - 'A']--;
					} 
				}
			}
			else {
				for (i = 0; i < len; i++) {
					if (isCoinLight[left[i] - 'A'] == -1 || isCoinTrue[left[i] - 'A'] == 1) {
						isCoinTrue[left[i] - 'A'] = 1;
						isCoinLight[left[i] - 'A'] = 0;
					}
					else {
						isCoinLight[left[i] - 'A'] = 1;
						isCoinTrue[left[i] - 'A']--;
					} 
					if (isCoinLight[right[i] - 'A'] == 1 || isCoinTrue[right[i] - 'A'] == 1) {
						isCoinTrue[right[i] - 'A'] = 1;
						isCoinLight[right[i] - 'A'] = 0;
					}
					else {
						isCoinLight[right[i] - 'A'] = -1;
						isCoinTrue[right[i] - 'A']--;
					} 
				}
			}
		}
		fake = 0;
		for (i = 0; i < 12; i++) {
			if (isCoinTrue[i] < 0 && isCoinApp[i] == true) {
				if (fake > isCoinTrue[i]) {
					fake = isCoinTrue[i];
					letter = char('A' + i);
					if (isCoinLight[i] == 1) result = "light.";
					else result = "heavy.";
				}
			}
		}
		cout << letter << " is the counterfeit coin and it is " << result << endl;
	}

	return 0;
}
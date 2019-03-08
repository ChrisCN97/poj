// poj 1013
// 2019.3.8

/* input:
3
ABCD EFGH even
ACI KJF up
IJ GH even
A B up
AB CF down
C D even
A B up
AB CD down
C D even
*/

/* output:
K is the counterfeit coin and it is light.
*/

// 12 dollars, 11 true
// has a different weight, not sure heavy or light
// three weighings to find the counterfeit coin

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
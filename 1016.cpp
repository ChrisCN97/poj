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

// simple check
// loop search

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string sComp[16], s;
	stringstream str;
	int i, count[10];
	bool quit = false;

	while (true) {
		cin >> sComp[0];
		if (sComp[0] == "-1") break;

		for (i = 1; i < 16; i++) sComp[i].clear();
		quit = false;
		s = sComp[0];
		for (int n = 1; n < 16; n++) {
			for (i = 0; i < 10; i++) count[i] = 0;
			for (i = 0; i < sComp[n - 1].size(); i++) count[sComp[n - 1][i] - '0']++;
			for (i = 0; i < 10; i++) {
				if (count[i] != 0) {
					str.str("");
					str << count[i] << i;
					sComp[n] += str.str();
				}
			}
			if (n == 1 && sComp[n] == s) {
				cout << s << " is self-inventorying" << endl;
				quit = true;
				break;
			}
			if (sComp[n] == sComp[n - 1]) {
				cout << s << " is self-inventorying after " << n - 1 << " steps" << endl;
				quit = true;
				break;
			}
			for (i = 0; i < n; i++) {
				if (sComp[n] == sComp[i]) {
					cout << s << " enters an inventory loop of length " << n - i << endl;
					quit = true;
					break;
				}
			}
			if (quit) break;
		}
		if (!quit) cout << s << " can not be classified after 15 iterations" << endl;
	}

	return 0;
}
// poj 1035
// 2019.4.16

/* input:
i
is
has
have
be
my
more
contest
me
too
if
award
#
me
aware
m
contest
hav
oo
or
i
fi
mre
#
*/

/* output:
me is correct
aware: award
m: i my me
contest is correct
hav: has have
oo: too
or:
i is correct
fi: i
mre: more me
*/

// 
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char dic[10001][16], check[51][16];
int dicNum = 0, checkNum = 0;

int main() {
	char s[16];
	while (true) {
		cin >> s;
		if (strcmp(s, "#")==0)
			break;
		strcpy_s(dic[dicNum], s);
		dicNum++;
	}
	while (true) {
		cin >> s;
		if (strcmp(s, "#")==0)
			break;
		strcpy_s(check[checkNum], s);
		checkNum++;
	}
	for (int c = 0; c < checkNum; c++) {
		string result = check[c];
		result += ":";
		int d;
		for (d = 0; d < dicNum; d++) {
			int dif = strlen(dic[d]) - strlen(check[c]);
			if (dif<2 && dif>-2) {
				if (strcmp(dic[d], check[c])==0) {
					cout << dic[d] << " is correct" << endl;
					break;
				}
				int m = 0, n = 0;
				bool flag = false;
				while (m < (int)strlen(dic[d]) && n < (int)strlen(check[c])) {
					if (dic[d][m] != check[c][n]) {
						if (flag)
							break;
						flag = true;
						if (dif == 0) {
							m++;
							n++;
						}
						else if(dif==-1)
							n++;
						else
							m++;
					}
					else {
						m++;
						n++;
					}
				}
				if (m == strlen(dic[d]) || n == strlen(check[c])) {
					result += " ";
					result += dic[d];
				}
			}
		}
		if (d == dicNum) {
			cout << result << endl;
		}
	}

	return 0;
}
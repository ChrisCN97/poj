// poj 1017
// 2019.3.11

/* input:
0 0 4 0 0 1
7 5 1 0 0 0
36 9 4 1 1 1
0 9 4 1 1 0
0 0 4 0 0 0
36 0 0 0 0 0
0 9 0 0 0 0
79 96 94 30 18 14
53 17 12 98 76 54
83 44 47 42 80 3
15 26 13 29 42 40
41 61 36 90 54 66
78 56 445 45 23 65
13 4 8 29 45 3
15 75 45 98 34 53
40 9 0 2 0 0
41 9 0 2 0 0
44 0 0 0 4 0
0 2 3 0 0 0
37 7 2 0 1 0
12 2 0 1 0 0
13 2 0 1 0 0
0 0 0 0 0 0
*/

/* output:
2
1

3
*/

// minimize the number of parcels
// box size: 6*6

#include <iostream>
using namespace std;

int main() {
	int s1, s2, s3, s4, s5, s6, result, temp;
	while (true) {
		result = 0;
		cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
		if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0) break;

		result += s6+s5;
		s1 = s1 - 11 * s5 > 0 ? s1 - 11 * s5 : 0;

		result += s4;
		temp = 20 * s4 - 4 * s2 > 0 ? 20 * s4 - 4 * s2 : 0;
		s2 = s2 - 5 * s4 > 0 ? s2 - 5 * s4 : 0;
		s1 = s1 - temp > 0 ? s1 - temp : 0;

		temp = s3 % 4;
		result += s3 / 4;
		result += temp > 0 ? 1 : 0;
		switch (temp) {
		case 1:
			temp = 5 - s2 > 0 ? 5 - s2 : 0;
			temp = 36 - 9 - (5 - temp) * 4;
			s2 = s2 - 5 > 0 ? s2 - 5 : 0;
			s1 = s1 - temp > 0 ? s1 - temp : 0;
			break;
		case 2:
			temp = 3 - s2 > 0 ? 3 - s2 : 0;
			temp = 36 - 18 - (3 - temp) * 4;
			s2 = s2 - 3 > 0 ? s2 - 3 : 0;
			s1 = s1 - temp > 0 ? s1 - temp : 0;
			break;
		case 3:
			temp = 1 - s2 > 0 ? 1 - s2 : 0;
			temp = 9 - (1 - temp) * 4;
			s2 = s2 - 1 > 0 ? s2 - 1 : 0;
			s1 = s1 - temp > 0 ? s1 - temp : 0;
			break;
		}

		result += s2 / 9;
		s2 %= 9;
		result += s2 > 0 ? 1 : 0;
		temp = s2 > 0 ? 36 - 4 * s2 : 0;
		s1 = s1 - temp > 0 ? s1 - temp : 0;

		result += s1 / 36;
		s1 %= 36;
		result += s1 > 0 ? 1 : 0;

		cout << result << endl;
	}

	return 0;
}
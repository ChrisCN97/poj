// poj 1008
// 2019.3.5

/* input:
3
10. zac 0
0. pop 0
10. zac 1995
*/

/* output:
3
3 chuen 0
1 imix 0
9 cimi 2801
*/

// Haab
// one year = 365 days = 19 months
// the first 18 months was 20 days long
// name: pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu
// the days of the months were denoted by numbers starting from 0 to 19
// last month was called uayet and had 5 days

// Tzolkin
// divided into 13 periods, each 20 days long
// name of the day:  imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau
// 1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk, 10 ok, 11 chuen, 12 eb, 13 ben, 1 ix, 2 mem, 3......

// Haab: NumberOfTheDay. Month Year 
// Tzolkin: Number NameOfTheDay Year 

// 算出Haab的总天数
// 转换成Tzolkin的日期

#include <iostream>
#include <string>
using namespace std;

const int HAABMONTH = 19, HAABDAY = 20, TzolTotalDay = 260, TzolDay = 20, TzolMon = 13;

int monthToDay(string month, string* haabMon) {
	for (int i = 0; i < HAABMONTH - 1; i++) {
		if (haabMon[i] == month) return i * HAABDAY;
	}
	return (HAABMONTH - 1) * HAABDAY;
}

int main() {
	
	int num, i, d, y, dayTotal, m2d, tzolYear, tzolMon;
	string m, tzold,
		haabMon[HAABMONTH - 1] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu" },
		tzolDay[TzolDay] = { "ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac" };

	cin >> num;
	cout << num << endl;
	for (i = 0; i < num; i++) {
		cin >> d >> m >> m >> y;

		m2d = monthToDay(m, haabMon);
		dayTotal = d + 1 + m2d + y * 365;

		tzolYear = (dayTotal - 1) / TzolTotalDay;
		dayTotal = (dayTotal % TzolTotalDay)==0 ? TzolTotalDay : dayTotal % TzolTotalDay;
		tzolMon = (dayTotal % TzolMon)==0 ? TzolMon : dayTotal % TzolMon;
		tzold = tzolDay[dayTotal % TzolDay];

		cout << tzolMon << " " << tzold << " " << tzolYear << endl;
	}

	return 0;
}
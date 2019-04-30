// poj 1042
// 2019.4.30

/* input:
2
1
10 1
2 5
2
4
4
10 15 20 17
0 3 4 3
1 2 3
4
4
10 15 50 30
0 3 4 3
1 2 3
0
*/

/* output:
45, 5
Number of fish expected: 31

240, 0, 0, 0
Number of fish expected: 480

115, 10, 50, 35
Number of fish expected: 724
*/

// 

#include <iostream>
using namespace std;

int lake, hour, f[30], d[30], t[30], time, staytime[30], earn;

int ifGoNextLake(int now) {
	int rTime = 0, nextLake = now;
	for (int m = now + 1; m < lake; m++) {
		int next = m, n;
		int nextE = f[next], nowE = 0, tempF[30];

		rTime += t[next];
		for (int n = 0; n < lake; n++)
			tempF[n] = f[n];

		for (n = 0; n < rTime + 2; n++) {
			int mLake = 0;
			for (int n = 1; n <= now; n++) {
				if (tempF[n] > tempF[mLake])
					mLake = n;
			}
			if (tempF[mLake] > 0)
				nowE += tempF[mLake];
			tempF[mLake] -= d[mLake];
		}
		if (nowE < nextE) {
			nextLake = next;
		}
	}
	
	return nextLake;
}

void fish(int nowL) {
	earn += f[nowL];
	f[nowL] -= d[nowL];
	time--;
	staytime[nowL]++;
}

int mostFishLake(int eLake) {
	int mLake = 0;
	bool flag = false;
	if (eLake == 0)
		return 0;
	for (int n = 1; n <= eLake; n++) {
		if (f[n] > 0 && f[n] > f[mLake]) {
			mLake = n;
			flag = true;
		}
	}
	if (!flag && f[0] <= 0)
		return -1;
	else
		return mLake;
}

int main() {
	while (true) {
		cin >> lake;
		if (lake == 0)
			break;
		cin >> hour;
		for (int n = 0; n < lake; n++)
			cin >> f[n];
		for (int n = 0; n < lake; n++)
			cin >> d[n];
		for (int n = 1; n < lake; n++)
			cin >> t[n];
		for (int n = 0; n < lake; n++)
			staytime[n] = 0;
		time = hour * 12;
		earn = 0;

		int nowL = 0, nextLake;
		while (time > 0) {
			if (nowL == lake - 1)
				break;
			if ((nextLake = ifGoNextLake(nowL)) != nowL) {
				int newTime = time;
				for (int n = nowL + 1; n <= nextLake; n++) {
					newTime -= t[n];
				}
				if (newTime > 0) {
					time = newTime;
					nowL = nextLake;
					fish(nowL);
				}
				else 
					break;
			}
			else {
				int sLake = mostFishLake(nowL);
				if (sLake == -1)
					break;
				fish(sLake);
			}
		}
		if (time > 0) {
			while (time > 0) {
				int sLake = mostFishLake(nowL);
				if (sLake == -1)
					break;
				fish(sLake);
			}
		}
		if (time > 0) {
			staytime[0] += time;
		}
		cout << staytime[0] * 5;
		for (int n = 1; n < lake; n++)
			cout << ", " << staytime[n] * 5;
		cout << endl;
		cout << "Number of fish expected: " << earn << endl;
	}

	return 0;
}
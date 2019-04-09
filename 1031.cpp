// poj 1031
// 2019.3.19

/* input:
0.5 1.7 3
1.0 3.0
2.0 -1.0
-4.0 -1.0

0.5 1.7 6
0.0 1.0
-0.5 0.5
0.0 -1.0
-1.0 -0.5
0.0 -2.0
2.0 0

0.5 1.7 6
0.0 1.0
1.0 0.0
0.0 -1.0
-1.0 0.0
0.0 -2.0
2.0 0

5.06 4.04 100
2.07 -13.61
3.00 -14.20
-0.00 -10.04
1.86 -11.80
3.39 -12.20
0.26 -9.71
1.50 -10.13
0.76 -9.49
0.41 -9.07
5.08 -10.77
5.58 -10.38
3.31 -9.47
3.83 -9.07
2.57 -8.64
5.82 -8.30
2.22 -7.97
0.49 -7.87
3.86 -7.37
3.04 -6.92
0.49 -7.31
0.60 -7.09
0.02 -7.23
3.53 -5.52
2.63 -5.57
2.90 -5.01
-0.27 -6.71
0.64 -5.78
-0.46 -6.50
-0.41 -6.35
2.21 -3.15
0.50 -4.28
1.65 -1.86
0.68 -2.91
0.24 -3.12
0.86 -1.22
0.12 -1.79
-0.14 -0.25
-0.81 -0.28
-1.40 -2.44
-1.82 -3.45
-2.16 -3.32
-2.34 -4.22
-2.89 -0.51
-2.54 -5.47
-3.49 -1.88
-3.84 -2.44
-3.88 -2.93
-3.40 -4.97
-3.92 -4.42
-5.70 -2.52
-6.50 -1.99
-3.99 -5.67
-5.81 -4.00
-3.99 -6.04
-3.57 -6.67
-3.83 -6.74
-8.21 -3.85
-8.67 -4.49
-3.98 -7.09
-6.19 -6.24
-4.09 -7.36
-5.11 -7.19
-6.31 -7.10
-6.43 -7.47
-7.10 -7.71
-4.44 -7.99
-6.50 -8.28
-6.86 -8.53
-9.64 -9.68
-9.41 -10.02
-6.45 -9.50
-6.99 -10.13
-7.88 -10.71
-8.06 -11.49
-7.10 -11.48
-4.35 -9.67
-4.76 -10.20
-6.53 -12.47
-5.46 -11.80
-4.70 -11.27
-6.18 -13.54
-3.24 -9.90
-4.04 -11.55
-3.71 -11.52
-2.90 -10.46
-2.81 -10.53
-2.66 -10.49
-2.61 -11.38
-2.27 -10.39
-2.42 -14.36
-1.93 -11.18
-1.48 -15.52
-1.26 -13.19
-0.72 -14.68
-1.24 -10.99
-1.26 -10.41
-0.46 -11.60
-1.09 -9.87
1.23 -14.03
1.78 -14.05
*/

/* output:
5.34

43.37
*/

// I = k * h * (a1 - a2)

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double Pi = 3.14159265;

int main() {
	int N, i;
	double k, h, r, pa, na, x, y, fa, min = 0, max = 0, da, sum = 0;
	bool ifN;
	cin >> k >> h >> N;
	cin >> x >> y;
	r = sqrt(x*x + y * y);
	if (y >= 0) pa = acos(x / r);
	else pa = 2 * Pi - acos(x / r);
	fa = pa;

	for (i = 0; i < N - 1; i++) {
		cin >> x >> y;
		r = sqrt(x*x + y * y);
		if (y >= 0) na = acos(x / r);
		else na = 2 * Pi - acos(x / r);
		double p = pa, n = na;
		if (na - pa > Pi) p = pa + 2 * Pi;
		if (pa - na > Pi) n = na + 2 * Pi;
		sum += n - p;
		min = min > sum ? sum : min;
		max = max < sum ? sum : max;
		pa = na;
		if (max - min >= 2 * Pi)
			break;
	}

	if (max - min < 2 * Pi) {
		double p = pa, n = fa;
		if (fa - pa > Pi) p = pa + 2 * Pi;
		if (pa - fa > Pi) n = fa + 2 * Pi;
		sum += n - p;
		min = min > sum ? sum : min;
		max = max < sum ? sum : max;
	}

	da = max - min >= 2 * Pi ? 2 * Pi : max - min;

	cout << setiosflags(ios::fixed) << setprecision(2) << k * h * da << endl;

	return 0;
}
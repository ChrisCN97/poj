#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
123.123 2
use string to save number
use vector to save number one by one
multi() to calculate one time multiplication
add the dot
*/

vector<int> multi(const vector<int> result, const vector<int> numList) {
	vector<int> temp(numList.size() + result.size());
	int t, jin = 0, i, j;
	for (i = 0; i < numList.size(); i++) {
		for (j = 0; j < result.size(); j++) {
			t = numList[i] * result[j] + jin;
			jin = t / 10;
			temp[i + j] += t % 10;
			if (temp[i + j] > 9) {
				temp[i + j + 1] += temp[i + j] / 10;
				temp[i + j] %= 10;
			}
		}
		if (jin != 0) {
			temp[i + j] += jin;
			jin = 0;
		}
	}
	if (temp.back() == 0) {
		temp.pop_back();
	}
	return temp;
}

int main() {
	string number;
	int power, dot, cDot, dZero, rLen, i;
	vector<int> numList, result;

	const int Length = 6;

	while (cin >> number >> power) {
		numList.clear();
		numList.reserve(Length - 1);
		dot = 0;
		for (i = Length - 1; i >= 0; i--) {
			if (number[i] != '.') {
				numList.push_back(number[i] - '0');
			}
			else {
				dot = Length - 1 - i;
			}
		}
		while (numList.back() == 0) numList.pop_back();

		result.clear();
		result = numList;
		for (i = 1; i < power; i++) {
			result = multi(result, numList);
		}

		dZero = 0;
		while (result.front() == 0) {
			result.erase(result.begin());
			dZero++;
		}
		cDot = dot * power - dZero;
		rLen = result.size();

		if (cDot >= rLen) {
			cout << '.';
			for (i = 0; i < cDot - rLen; i++) cout << '0';
			for (i = rLen - 1; i >= 0; i--) {
				cout << result[i];
			}
		}
		else if (cDot > 0) {
			for (i = rLen - 1; i >= 0; i--) {
				if (i == cDot - 1) cout << '.';
				cout << result[i];
			}
		}
		else {
			for (i = rLen - 1; i >= 0; i--) {
				cout << result[i];
			}
			for (i = 0; i > cDot; i--) cout << '0';
		}
		cout << endl;
	}
	return 0;
}
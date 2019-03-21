// poj 1033
// 2019.3.20

/* input:
20 3
4 2 3 11 12
1 7
3 18 5 10

5 4
1 4
1 1
1 2
1 3

5 2
1 1
2 2 3
*/

/* output:
2 1
3 2
11 3
12 4
18 6
10 8
5 20
7 5
20 7
*/

// In this file system all disk space is divided into N clusters of the equal sizes from 1 to N.
// Each file occupies one or more clusters 
// fastest way: all its clusters are situated in the successive disk clusters in the natural order
// all files are numbered beforehand by integers from 1 to K in the order of descending frequency of access
// reading of one occupied cluster from the disk to the memory and writing its contents to some free cluster
// place the files on the disk in the optimal way by executing the minimal possible number of cluster-moving operations
// If the files on the disk are already placed in the optimal way the output should contain only the string "No optimization needed".

#include <iostream>
using namespace std;

int *map, total = 0, m;

void dfs(int i, int head) {
	if (map[i] == 0)
		return;
	if (map[i] == head) {
		for (int n = m; n > 0; n--) {
			if (map[n] == 0) {
				map[n] = map[i];
				cout << i << " " << n << endl;
				map[i] = 0;
				return;
			}	
		}
	}
	dfs(map[i], head);
	map[map[i]] = map[i];
	cout << i << " " << map[i] << endl;
	map[i] = 0;
	return;
}

int main() {
	int group, i, count = 0;
	cin >> m >> group;
	map = new int[m + 1];
	for (i = 0; i < m + 1; i++)
		map[i] = 0;
	while (group--) {
		int num, n;
		cin >> num;
		for (i = 0; i < num; i++) {
			count++;
			cin >> n;
			map[n] = count;
		}
	}
	int perfect = 0;
	for (i = 0; i < m + 1; i++) {
		if (total == count)
			break;
		if (map[i] == 0)
			continue;
		if (map[i] == i) {
			perfect++;
			total++;
			continue;
		}
		dfs(i, i);
	}
	if (perfect == count)
		cout << "No optimization needed" << endl;

	delete map;
	return 0;
}
// poj 1033
// 2019.3.20

/* input:
20 3
4 2 3 11 12
1 7
3 18 5 10
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

int main() {
	

	return 0;
}
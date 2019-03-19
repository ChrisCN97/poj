// poj 1027
// 2019.3.18

/* input:
3
RGGBBGGRBRRGGBG
RBGRBGRBGRBGRBG
RRRRGBBBRGGRBBB
GGRGBGGBRRGGGBG
GBGGRRRRRBGGRRR
BBBBBBBBBBBBBBB
BBBBBBBBBBBBBBB
RRRRRRRRRRRRRRR
RRRRRRGGGGRRRRR
GGGGGGGGGGGGGGG

RRRRRRRRRRRRRRR
RRRRRRRRRRRRRRR
GGGGGGGGGGGGGGG
GGGGGGGGGGGGGGG
BBBBBBBBBBBBBBB
BBBBBBBBBBBBBBB
RRRRRRRRRRRRRRR
RRRRRRRRRRRRRRR
GGGGGGGGGGGGGGG
GGGGGGGGGGGGGGG

RBGRBGRBGRBGRBG
BGRBGRBGRBGRBGR
GRBGRBGRBGRBGRB
RBGRBGRBGRBGRBG
BGRBGRBGRBGRBGR
GRBGRBGRBGRBGRB
RBGRBGRBGRBGRBG
BGRBGRBGRBGRBGR
GRBGRBGRBGRBGRB
RBGRBGRBGRBGRBG
*/

/* output:
Game 1:

Move 1 at (4,1): removed 32 balls of color B, got 900 points.
Move 2 at (2,1): removed 39 balls of color R, got 1369 points.
Move 3 at (1,1): removed 37 balls of color G, got 1225 points.
Move 4 at (3,4): removed 11 balls of color B, got 81 points.
Move 5 at (1,1): removed 8 balls of color R, got 36 points.
Move 6 at (2,1): removed 6 balls of color G, got 16 points.
Move 7 at (1,6): removed 6 balls of color B, got 16 points.
Move 8 at (1,2): removed 5 balls of color R, got 9 points.
Move 9 at (1,2): removed 5 balls of color G, got 9 points.
Final score: 3661, with 1 balls remaining.

Game 2:

Move 1 at (1,1): removed 30 balls of color G, got 784 points.
Move 2 at (1,1): removed 30 balls of color R, got 784 points.
Move 3 at (1,1): removed 30 balls of color B, got 784 points.
Move 4 at (1,1): removed 30 balls of color G, got 784 points.
Move 5 at (1,1): removed 30 balls of color R, got 784 points.
Final score: 4920, with 0 balls remaining.

Game 3:

Final score: 0, with 150 balls remaining.
*/

// the game is over when every ball is removed or when every cluster has only one ball
// When a cluster of m balls is removed, the player's score increases by (m-2)^2
// A bonus of 1000 is given if every ball is removed at the end of the game. 
// choose the ball that gives the largest possible cluster at each step
// choose the leftmost ball 
// choose the bottommost ball

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Map {
	int color;
	bool check;
};

struct Point {
	int x;
	int y;
};

Map map[15][10];
int pointCount;
int area;
Point lbPoint;

bool bfs(int x, int y) {
	int head = 0, tail = 1;
	Point pSet[151];
	pSet[head].x = x;
	pSet[head].y = y;
	lbPoint.x = x;
	lbPoint.y = y;
	area = 0;
	map[x][y].check = true;
	while (head < tail) {
		int x = pSet[head].x;
		int y = pSet[head].y;
		Point point;
		point.x = x;
		point.y = y;
		
		if (x < lbPoint.x)
			lbPoint = point;
		else if (x == lbPoint.x && y < lbPoint.y)
			lbPoint = point;
		area++;

		if (y != 9 && !map[x][y + 1].check && map[x][y + 1].color == map[x][y].color) {
			pSet[tail].x = x;
			pSet[tail++].y = y + 1;
			map[x][y + 1].check = true;
		}
		if (y != 0 && !map[x][y - 1].check && map[x][y - 1].color == map[x][y].color) {
			pSet[tail].x = x;
			pSet[tail++].y = y - 1;
			map[x][y - 1].check = true;
		}
		if (x != 0 && !map[x - 1][y].check && map[x - 1][y].color == map[x][y].color) {
			pSet[tail].x = x - 1;
			pSet[tail++].y = y;
			map[x - 1][y].check = true;
		}
		if (x != 14 && !map[x + 1][y].check && map[x + 1][y].color == map[x][y].color) {
			pSet[tail].x = x + 1;
			pSet[tail++].y = y;
			map[x + 1][y].check = true;
		}

		++head;
	}

	return true;
}

void bfsClear(int x, int y) {
	Point pSet[151];
	int head = 0, tail = 1;
	pSet[head].x = x;
	pSet[head].y = y;
	while (head < tail) {
		int x = pSet[head].x;
		int y = pSet[head].y;
		map[x][y].check = false;

		if (y != 9 && map[x][y + 1].check && map[x][y + 1].color == map[x][y].color) {
			pSet[tail].x = x;
			pSet[tail++].y = y + 1;
			map[x][y + 1].check = false;
		}
		if (y != 0 && map[x][y - 1].check && map[x][y - 1].color == map[x][y].color) {
			pSet[tail].x = x;
			pSet[tail++].y = y - 1;
			map[x][y - 1].check = false;
		}
		if (x != 0 && map[x - 1][y].check && map[x - 1][y].color == map[x][y].color) {
			pSet[tail].x = x - 1;
			pSet[tail++].y = y;
			map[x - 1][y].check = false;
		}
		if (x != 14 && map[x + 1][y].check && map[x + 1][y].color == map[x][y].color) {
			pSet[tail].x = x + 1;
			pSet[tail++].y = y;
			map[x + 1][y].check = false;
		}

		map[x][y].color = -1;
		pointCount++;
		++head;
	}
}

int main() {
	int caseNum, x, y, i, score, turn;
	string s;
	cin >> caseNum;
	for (turn = 1; turn <= caseNum; turn++) {
		for (y = 9; y >= 0; y--) {
			cin >> s;
			for (x = 0; x < 15; x++) {
				switch (s[x]) {
				case 'R':
					map[x][y].color = 0;
					break;
				case 'G':
					map[x][y].color = 1;
					break;
				case 'B':
					map[x][y].color = 2;
					break;
				}
			}
		}
		score = 0;
		pointCount = 0;

		cout << "Game " << turn << ":\n" << endl;

		int move = 0;
		while (true) {
			for (y = 0; y < 10; y++) {
				for (x = 0; x < 15; x++) {
					map[x][y].check = false;
				}
			}
			move++;
			int maxarea = 0;
			Point lbMaxPoint;
			for (y = 0; y < 10; y++) {
				for (x = 0; x < 15; x++) {
					if (map[x][y].color == -1 || map[x][y].check)
						continue;
					bfs(x, y);
					if (area < 2)
						continue;
					if (area > maxarea) {
						maxarea = area;
						lbMaxPoint = lbPoint;
					}
					else if (area == maxarea) {
						if(lbPoint.x< lbMaxPoint.x)
							lbMaxPoint = lbPoint;
						else if(lbPoint.x == lbMaxPoint.x && lbPoint.y < lbMaxPoint.y)
							lbMaxPoint = lbPoint;
					}
				}
			}

			if (maxarea == 0) {
				if (pointCount == 150)
					score += 1000;
				break;
			}
			
			char ch;
			switch (map[lbMaxPoint.x][lbMaxPoint.y].color) {
			case 0:
				ch = 'R';
				break;
			case 1:
				ch = 'G';
				break;
			case 2:
				ch = 'B';
				break;
			}
			int sc = pow(maxarea - 2, 2);
			cout << "Move " << move << " at (" << lbMaxPoint.y + 1 << "," << lbMaxPoint.x + 1 << "): removed " << maxarea << " balls of color "
				<< ch << ", got " << sc << " points." << endl;
			score += sc;

			bfsClear(lbMaxPoint.x, lbMaxPoint.y);

			int nr = 0, pr = 0, nc = 0, pc = 0;
			for (nc = 0, pc = 0; nc < 15; nc++) {
				for (nr = 0, pr = 0; nr < 10; nr++) {
					if (map[nc][nr].color != -1) {
						if (nr != pr) {
							int temp = map[nc][nr].color;
							map[nc][nr].color = map[nc][pr].color;
							map[nc][pr].color = temp;
						}
						pr++;
					}
				}
				if (pr != 0) {
					if (nc != pc) {
						for (int a = 0; a < 10; a++) {
							int temp = map[pc][a].color;
							map[pc][a].color = map[nc][a].color;
							map[nc][a].color = temp;
						}
					}
					pc++;
				}
			}
		}

		cout << "Final score: " << score << ", with " << 150 - pointCount << " balls remaining." << endl << endl;
			
	}

	return 0;
}
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
#include <vector>
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

struct PointSet {
	vector<Point> set;
	Point lbPoint;
};

Map map[15][10];
int pointCount;

bool dfs(int x, int y, PointSet &pointSet) {
	Point point;
	point.x = x;
	point.y = y;
	map[x][y + 1].check = true;
	if(pointSet.set.size()==0)
		pointSet.lbPoint = point;
	else {
		for (int i = 0; i < pointSet.set.size(); i++) {
			if (x < pointSet.set[i].x && y < pointSet.set[i].y)
				pointSet.lbPoint = point;
		}
	}
	pointSet.set.push_back(point);
	pointCount++;
	if (y != 9 && !map[x][y + 1].check && map[x][y + 1].color == map[x][y].color)
		dfs(x, y + 1, pointSet);
	if (y != 0 && !map[x][y - 1].check && map[x][y - 1].color == map[x][y].color)
		dfs(x, y + 1, pointSet);
	if (x != 0 && !map[x - 1][y].check && map[x - 1][y].color == map[x][y].color)
		dfs(x - 1, y, pointSet);
	if (x != 14 && !map[x + 1][y].check && map[x + 1][y].color == map[x][y].color)
		dfs(x + 1, y, pointSet);

	return true;
}

int main() {
	int caseNum, x, y, i, score, turn;
	string s;
	vector<PointSet> pointSetList;
	cin >> caseNum;
	for (turn = 1; turn <= caseNum; turn++) {
		for (y = 14; y >= 0; y--) {
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
			pointSetList.clear();
			move++;

			for (y = 0; y < 10; y++) {
				for (x = 0; x < 15; x++) {
					if (map[x][y].color == -1 || map[x][y].check)
						continue;
					PointSet pointSet;
					dfs(x, y, pointSet);
					if (pointSet.set.size() < 2)
						continue;
					pointSetList.push_back(pointSet);
				}
			}

			if (pointSetList.size() == 0)
				break;

			int m = 0, maxi;

			for (i = 0; i < pointSetList.size(); i++) {
				if (pointSetList[i].set.size() > m) {
					m = pointSetList[i].set.size();
					maxi = i;
				}
			}
			PointSet result;
			char ch;
			result = pointSetList[maxi];
			switch (map[result.lbPoint.x][result.lbPoint.y].color) {
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
			int sc = pow(m - 2, 2);
			cout << "Move " << move << " at(" << result.lbPoint.x << ", " << result.lbPoint.y << ") : removed " << result.set.size() << " balls of color "
				<< ch << ", got " << sc << " points." << endl;
			score += sc;
			
			for (i = 0; i < result.set.size(); i++) 
				map[result.set[i].x][result.set[i].y].color = -1;
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

		cout << "Final score: " << score << ", with " << 150 - pointCount << " balls remaining." << endl;

		if (caseNum != turn)
			cin >> s;
	}

	return 0;
}
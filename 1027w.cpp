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
using namespace std;

struct Map {
	int color;
	int group;
};

int main() {
	int caseNum, x, y;
	string s;
	Map map[15][10];
	cin >> caseNum;
	while (caseNum--) {
		for (y = 0; y < 10; y++) {
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

		while (true) {
			

			for (y = 0; y < 10; y++) {
				for (x = 0; x < 15; x++) 
					map[x][y].group = -1;
			}

			for (y = 0; y < 10; y++) {
				for (x = 0; x < 15; x++) {

				}
			}

		}

		if (caseNum != 0)
			cin >> s;
	}

	return 0;
}
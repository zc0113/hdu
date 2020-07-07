#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 301

using namespace std;

int mvx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int mvy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int isright[MAX_SIZE][MAX_SIZE], step[MAX_SIZE][MAX_SIZE];

typedef struct knight{
	int x, y;
}knight;

knight kg, lg; 

void Bfs(int l) {
	queue<knight> q;
	q.push(kg);
	//q.push(kg.x);
	//q.push(kg.y);
	isright[kg.x][kg.y] = 1;
	knight out;
	while (!q.empty()) {
		out = q.front();
		q.pop();
		//out.x = q.front();
		//cout << "kg.x : " << kg.x << endl;
		//q.pop();
		//out.y = q.front();
		//q.pop();
		if (out.x == lg.x && out.y == lg.y) {
			cout << step[lg.x][lg.y] << endl;
			return;
		}
		knight tmp;
		for (int i = 0; i < 8; ++i) {
			tmp.x = out.x + mvx[i], tmp.y = out.y + mvy[i];		
			if ((tmp.x < l && tmp.x >= 0) && (tmp.y < l && tmp.y >= 0) && !isright[tmp.x][tmp.y]) {
				//cou << "tx = " << tmp.x << "ty = " << tmp.y << endl;
				//q.push(tmp.x);
				//q.push(tmp.y);
				q.push(tmp);
				isright[tmp.x][tmp.y] = 1;
				step[tmp.x][tmp.y] = step[out.x][out.y] + 1;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int l;
		cin >> l;
		cin >> kg.x >> kg.y >> lg.x >> lg.y;
		//cout << "kg.x : " << kg.x << "kg.y : " << kg.y << "kg.u : " << kg.u << "kg.v : " << kg.v << endl;
		memset(step, 0, sizeof(step));
		memset(isright, 0, sizeof(isright));
		Bfs(l);
	}
	return 0;
}
/*
Sample Input

3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1
Sample Output

5
28
0
*/
/*
1
8
0 0 
7 0
*/

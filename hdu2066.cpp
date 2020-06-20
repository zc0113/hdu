#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int** mp = new int*[2000];
int* book  = new int[2000];
int* dis = new int[2000];
int* d = new int[2000];
int* s = new int[2000];
int T, S, D;

void dijkstra(int n) {
	book[0] = 1;//0点默认访问 
	for (int i = 0; i <= n; ++i) {
		dis[i] = mp[0][i];
	}
	for (int i = 0; i < n; ++i) {
		int minn = INF, idx;
		for (int j = 1; j <= n; ++j) {
			if (!book[j] && dis[j] < minn) {
				minn = dis[j];
				idx = j;
			}
		}
		book[idx] = 1;
		for (int j = 1; j <= n; ++j) {
			if (!book[j] && dis[idx] + mp[idx][j] < dis[j]) {
				dis[j] = dis[idx] + mp[idx][j];
			}
		}
	}
}

int main() {
	for (int i = 0; i < 2000; ++i) {
		mp[i] = new int[2000];
	}
	while (cin >> T >> S >> D) {
		int n = 0;
		for (int i = 0; i < 2000; ++i) {
			for (int j = 0; j < 2000; ++j) {
				if (i == j) {
					mp[i][j] = 0;
				} else {
					mp[i][j] = INF;
				}
			}
		}
		int a, b, time;
		for (int i = 0; i < T; ++i) {
			cin >> a >> b >> time;
			n = max(max(n, a), b);
			if (time < mp[a][b]) mp[b][a] = mp[a][b] = time;
		}
		for (int i = 0; i < 2000; ++i) {
			book[i] = 0;
		}
		for (int i = 0; i < S; ++i) {
			cin >> s[i];
			mp[0][s[i]] = mp[s[i]][0] = 0;//相邻城市,这里假设起始城市为0点 
		}
		dijkstra(n);
		int res = INF;
		for (int i = 0; i < D; ++i) {
			cin >> d[i];
		}
		for (int i = 0; i < D; ++i) {
			res = min(res, dis[d[i]]);
		}
		cout << res << endl;
	}
	for (int i = 0; i < 2000; ++i) {
		delete [] mp[i];
	}
	delete [] mp;
	delete [] book;
	delete [] d;
	delete [] dis;
	delete [] s;
	return 0; 
}

/*
Sample Input
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10
 

Sample Output
9
*/

#include <string.h>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int mp[250][250];
int book[250];
int dis[250];

void dijkstra(int n, int s, int t) {
	for (int i = 0; i < n; ++i) {
		dis[i] = mp[s][i];
	}
	book[s] = 1;
	for (int i = 0; i < n; ++i) {
		int minn = INF, c;
		for (int j = 0; j < n; ++j) {
			if (!book[j] && dis[j] < minn) {
				minn = dis[j];
				c = j;
			}
		}
		book[c] = 1;
		for (int k = 0; k < n; ++k) {
			if (!book[k] && dis[c] + mp[c][k] < dis[k]) {
				dis[k] = dis[c] + mp[c][k];
			}
		}
	}
	if (dis[t] < INF) {
		cout << dis[t] << endl;
	} else {
		cout << "-1" << endl;
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				mp[i][j] = i == j ? 0 : INF;
			}
		}
		memset(book, 0, sizeof(book));
		int a, b, x;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> x;
			if (x < mp[a][b]) {
				mp[a][b] = mp[b][a] = x;
			}
		}
		int s, t;
		cin >> s >> t;
		dijkstra(n, s, t);
	}
	return 0;
}
/*
Sample Input
3 3
0 1 1
0 2 3
1 2 1
0 2
3 1
0 1 1
1 2
 

Sample Output
2
-1
*/

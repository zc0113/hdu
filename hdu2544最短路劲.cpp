#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

int mp[101][101];//保存各点路径 
int book[101];//记录点否被访问 
int dis[101];//记录始末距离 
int n, m;//点，路径数量 

void dijkstra() {
	for (int i = 1; i <= n; ++i) {
		dis[i] = mp[1][i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int min = INF, idx;
		for (int j = 1; j <= n; ++j) {//找到距离上一个点最近的点 
			if (!book[j] && dis[j] < min) {
				min = dis[j];
				idx = j;//记录最近点 
			}
		}
		book[idx] = 1;//标记找到的最近点
		for (int j = 1; j <= n; ++j) {//更新其他点到初始点的最短距离 
			if (!book[j] && dis[idx] + mp[idx][j] < dis[j]) {
				dis[j] = dis[idx] + mp[idx][j];
			}
		}
	}
	cout << dis[n] << endl;
}

//初始化路径距离表
int main() {
	while (cin >> n >> m && (n + m)) {
		for (int i = 1; i <= n; ++i) {//从标点1开始 
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					mp[i][j] = 0;
				} else {
					mp[i][j] = INF;
				}
			}
		}
		memset(book, 0, sizeof(book));
		int u, v, w;
		for (int i = 0; i < m; ++i) {//读入点之间路径值 
			cin >> u >> v >> w;
			if (w < mp[u][v]) mp[u][v] = mp[v][u] = w;
		}
		dijkstra();
	}
	return 0;
} 



/*
Sample Input
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0


Sample Output
3
2
*/

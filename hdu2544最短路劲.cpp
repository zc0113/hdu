#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

int mp[101][101];//�������·�� 
int book[101];//��¼��񱻷��� 
int dis[101];//��¼ʼĩ���� 
int n, m;//�㣬·������ 

void dijkstra() {
	for (int i = 1; i <= n; ++i) {
		dis[i] = mp[1][i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int min = INF, idx;
		for (int j = 1; j <= n; ++j) {//�ҵ�������һ��������ĵ� 
			if (!book[j] && dis[j] < min) {
				min = dis[j];
				idx = j;//��¼����� 
			}
		}
		book[idx] = 1;//����ҵ��������
		for (int j = 1; j <= n; ++j) {//���������㵽��ʼ�����̾��� 
			if (!book[j] && dis[idx] + mp[idx][j] < dis[j]) {
				dis[j] = dis[idx] + mp[idx][j];
			}
		}
	}
	cout << dis[n] << endl;
}

//��ʼ��·�������
int main() {
	while (cin >> n >> m && (n + m)) {
		for (int i = 1; i <= n; ++i) {//�ӱ��1��ʼ 
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
		for (int i = 0; i < m; ++i) {//�����֮��·��ֵ 
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

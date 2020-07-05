#include <iostream>
#include <cmath>
#include <cstring>
#define MAX_SIZE 101

using namespace std;

int map[MAX_SIZE][MAX_SIZE];//��Ǿ����Ƿ�ɴ� 
int visit[MAX_SIZE];//�������������Ķ�
int link[MAX_SIZE];//�����ܽ����ĵ���ı�� 
int gn = 0, gm = 0;

typedef struct node{
	double x, y;//x,y���� 
}node;

double Dis(node g, node h) {//����������� 
	return sqrt((g.x - h.x) * (g.x - h.x) + (g.y - h.y) * (g.y - h.y));
}

bool Isright(int k) {//�����ܷ��붴 
	for (int i = 1; i <= gm; ++i) {
		if (visit[i] == 0 && map[k][i]) {
			visit[i] = 1;
			if (link[i] == 0 || Isright(link[i])) {
				link[i] = k;
				return true;
			}
		}
	}
	return false;
}

int Arrive() {
	int count = 0;
	for (int i = 1; i <= gn; ++i) {
		memset(visit, 0, sizeof(visit));
		if (Isright(i)) count++;
	}
	return count;
}

int main() {
	int n, m;
	double t = 0.0, v = 0.0;
	node gopher[MAX_SIZE], hole[MAX_SIZE];
	while (cin >> n >> m >> t >> v) {
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(link, 0, sizeof(link));
		double s = t * v;//�������ܵ�·�� 
		for (int i = 1; i <= n; ++i) {
			cin >> gopher[i].x >> gopher[i].y;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> hole[i].x >> hole[i].y;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (s >= Dis(gopher[i], hole[j])) {
					map[i][j] = 1;			
				}
			}
		}
		gn = n;
		gm = m;
		cout << n - Arrive() << endl;
	}
	return 0;
}

/*
Sample Input

2 2 5 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0
Sample Output

1
*/

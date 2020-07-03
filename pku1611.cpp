#include <iostream>
#define MAX_SIZE 30010

using namespace std;

int parent[MAX_SIZE];
int high[MAX_SIZE];

void make_set(int x) {
	parent[x] = x;//每个数字一个集合并且根节点是本身 
	high[x] = 1;//每个集合的深度 
}

int find_set(int x) {
	if (x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a == b) return;
	if (high[a] <= high[b]) {//合并不在一起的集合 
		parent[a] = b;
		high[b] += high[a];
	} else {
		parent[b] = a;
		high[a] += high[b];
	}
}

int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		for (int i = 0; i < n; ++i) {
			make_set(i);
		}
		int u, head;
		for (int i = 0; i < m; ++i) {
			cin >> u >> head;//每组的个数，以及第一个人 
			int v;//后面的人 
			for (int j = 0; j < u - 1; ++j) {
				cin >> v;
				union_set(head, v);
			}
		}
		cout << high[find_set(0)] << endl;
	}
	return 0;
} 

/*
Sample Input

100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2
200 2
1 5
5 1 2 3 4 5
1 0
0 0
Sample Output

4
1
1
*/

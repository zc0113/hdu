#include <iostream>
#define MAX_SIZE 30010

using namespace std;

int parent[MAX_SIZE];
int high[MAX_SIZE];

void make_set(int x) {
	parent[x] = x;//ÿ������һ�����ϲ��Ҹ��ڵ��Ǳ��� 
	high[x] = 1;//ÿ�����ϵ���� 
}

int find_set(int x) {
	if (x != parent[x]) parent[x] = find_set(parent[x]);
	return parent[x];
}

void union_set(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a == b) return;
	if (high[a] <= high[b]) {//�ϲ�����һ��ļ��� 
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
			cin >> u >> head;//ÿ��ĸ������Լ���һ���� 
			int v;//������� 
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

#include <iostream>
#define MAX_SIZE 50010

using namespace std;

int parent[MAX_SIZE];
int high[MAX_SIZE];
int count;//假设宗教总数是学生总数 

void Make_set(int x) {
	parent[x] = x;
	high[x] = 1;
}

int Find_set(int x) {
	if (x != parent[x]) parent[x] = Find_set(parent[x]);
	return parent[x];
}

void Union_set(int x, int y) {
	x = Find_set(x);
	y = Find_set(y);
	if (x == y) return;
	count--;//每有一对信仰一个宗教，则总的宗教少一 
	if (high[x] <= high[y]) {
		parent[x] = y;
		high[y] += high[x];
	} else {
		parent[y] = x;
		high[x] += high[y];
	}
	
}

int main() {
	int n, m, cas = 1;
	while (cin >> n >> m && (n || m)) {
		count = n;
		//int count = 0;
		for (int i = 1; i < n + 1; ++i) {
			Make_set(i);
		}
		int u, v;
		for (int i = 0; i < m; ++i) {
			cin >> u >> v;
			Union_set(u, v);
		}
		//for (int i = 1; i < n + 1; ++i) {
		//	if (parent[i] == i) count++;//根节点不是自己，说明跟别人信仰了一个 宗教 
		//}
		cout << "Case " << cas++ << ": " << count << endl;
	}
	return 0;
}

/*
Sample Input

10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0
Sample Output

Case 1: 1
Case 2: 7
*/

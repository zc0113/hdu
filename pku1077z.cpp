#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct node {
	int a[9];
	int count, index, f, c;
	node() {}
	node(int* t, int step, int Idx, int fa) {
		for (int i = 0; i < 9; ++i) {
			a[i] = t[i];
		}
		count = step;
		index = Idx;
		f = fa;
	}
	
	void set(int* t, int step, int Idx, int fa, int C) {
		for (int i = 0; i < 9; ++i) {
			a[i] = t[i];
		}
		count = step;
		index = Idx;
		f = fa;
		c = C;
	}
	bool operator==(int* t) {
		for (int i = 0; i < 9; ++i) {
			if (a[i] != t[i]) return false;
		}
		return true;
	}
	//bool Cmp() {
	//	for (int i = 0; i < 8; ++i) {
	//		if (a[i] != i + 1) return false;
	//	}
	//	return true;
//	}
	
	int Hash_val() {
		int ans = 0, m = 1;
		for (int i = 0; i < 9; ++i) {
			int k = 0;
			for (int j = 0; j < i; ++j) {
				if (a[j] > a[i]) k++;
			}
			ans += m * k;
			m *= i + 1;
		}
		return ans;
	}
}S, now, to;

node Q[10000000];

int Bfs() {
	int front = 0, rear = 0;
	int dir[4] = {-3, 3, -1, 1};
	bool used[362889];
	int t[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
	Q[rear++] = S;
	for (int i = 0; i < 362889; ++i) {
		used[i] = false;
	}
	used[S.Hash_val()] = true;
	while (front != rear) {
		now = Q[front++];
		if (now == t) return front - 1;
		//if (now.Cmp()) return front - 1;
		int i;
		for (i = 0; i < 2; ++i) {
			int p = now.index + dir[i];
			if (p >= 0 && p < 9) {
				to.set(now.a, now.count + 1, now.index + dir[i], front - 1, i);
				swap(to.a[now.index], to.a[to.index]);
				int t = to.Hash_val();
				if (!used[t]) {
					Q[rear++] = to;
					used[t] = true;
				}
			}
		}
		for (i; i < 4; ++i) {
			int fp = (now.index / 3) * 3;
			int p = now.index + dir[i];
			if (fp <= p && p < fp + 3) {
				to.set(now.a, now.count + 1, now.index + dir[i], front - 1, i);
				swap(to.a[now.index], to.a[to.index]);
				int t = to.Hash_val();
				if (!used[t]) {
					Q[rear++] = to;
					used[t] = true;
				}
			}
		}
	}
	return -1;
}

char cc[] = "udlr";
int ans[10000000];

int main() {
	char s[20];
	int a[20];
	int t;
	while (gets(s)) {
		for (int i = 0, j = 0; i < strlen(s); ++i) {
			if (isdigit(s[i])) {
				a[j++] = s[i] - '0';
			} else if (s[i] == 'x') {
				t = j;
				a[j++] = 0;
			}
		}
		S = node(a, 0, t, -1);
		int F = Bfs();
		if (F != -1) {
			int begin = 0;
			while (Q[F].f != -1) {
				ans[begin++] = Q[F].c;
				F = Q[F].f;
			}
			while (begin > 0) {
				cout << cc[ans[--begin]];
			}
			cout << endl;
		} else {
			cout << "unsolvable" << endl;
		}
	}
	return 0;
} 

/*Sample Input

2 3 4 1 5 x 7 6 8

Sample Output

ullddrurdllurdruldr
*/

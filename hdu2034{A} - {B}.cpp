#include <set>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n, m, val;
	set<int> res;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		res.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &val);
			res.insert(val);
		}
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &val);
			if (res.find(val) != res.end()) {
				res.erase(val);
			}
		}
		if (res.empty()) {
			printf("NULL\n");
		} else {
			for (set<int>::iterator it = res.begin(); it != res.end(); ++it) {
				printf("%d ", *it);
			}
			printf("\n");
		}
	}
	return 0;
}

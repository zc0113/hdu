#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m, val;
	set<int> res;
	while (cin >> n >> m) {
		res.clear();
		for (int i = 1; i <= n + m; ++i) {
			cin >> val;
			res.insert(val);
		}
		bool flag = false;
		for (set<int>::iterator it = res.begin(); it != res.end(); ++it) {
			if (flag) {
				cout << " ";
			}
			flag = true;
			cout << *it;
		}
		cout << endl;
	}
	return 0;
} 

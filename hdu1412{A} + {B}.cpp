#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m, val;
	while (cin >> n >> m) {
		set<int> res; 
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



/*
Sample Input
1 2
1
2 3
1 2
1
1 2
 

Sample Output
1 2 3
1 2

*/

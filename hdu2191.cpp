#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 2008

using namespace std;

int dp[MAX];
int p[MAX], h[MAX];

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int pp, hh, c;
		int idx = 0;
		for (int i = 0; i < m; ++i) {
			cin >> pp >> hh >> c;
			while (c--) {//转换成多个粮食 
				p[idx] = pp;
				h[idx] = hh;
				idx++;
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < idx; ++i) {
			for (int j = n; j >= p[i]; --j) {
				dp[j] = max(dp[j], dp[j - p[i]] + h[i]);
			}
			
		}
		cout << dp[n] << endl;
	}
	return 0;
}

/*

Sample Input
1
8 2
2 100 4
4 100 2
 

Sample Output
400

*/

#include <iostream>
#define INF 0x7fffffff
#define min(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int dp[10010];
int p[50010];
int w[10010];

int main() {
	int t;//测试用例数量 
	cin >> t;
	int e, f;//空猪罐，满猪重量
	int m, n;//硬币总重,硬币数量 
	while (t--) {
		cin >> e >> f;
		m = f - e; 
		cin >> n;
		for (int i = 1; i <= n; ++i) {//读入硬币价值和重量 
			cin >> p[i] >> w[i];
		}
		dp[0] = 0;
		for (int i = 1; i <= m; ++i) {//初始化 
			dp[i] = INF;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = w[i]; j <= m; j++) {
				if (dp[j - w[i]] != INF) {
					dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
				}
			}
		}
		if (dp[m] != INF) {
			cout << "The minimum amount of money in the piggy-bank is " << dp[m]  << "." << endl;
		} else {
			cout << "This is impossible." <<endl;
		}
	}
	return 0;
}

/*
Sample Input

3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
Sample Output

The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.
*/

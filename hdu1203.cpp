#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX_SIZE 10010

using namespace std;

double dp[MAX_SIZE];
int cost[MAX_SIZE];
double p[MAX_SIZE];

int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		for (int i = 1; i <= m; ++i) {
			cin >> cost[i] >> p[i];
			p[i] = 1 - p[i];//得不到offer的概率 
		}
		for (int i = 0; i <= n; ++i) {
			dp[i] = 1;
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = n; j >= cost[i]; --j) {
				dp[j] = min(dp[j], dp[j - cost[i]] * (p[i]));
			}
		}
		printf("%.1lf%%\n", (1 - dp[n]) * 100);
	}
	return 0;
}
/*
Sample Input
10 3
4 0.1
4 0.2
5 0.3
0 0
 

Sample Output
44.0%
*/

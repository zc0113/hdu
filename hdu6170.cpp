#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 2510

using namespace std;

int dp[MAX_SIZE][MAX_SIZE];//dp[i][j]代表s2前i个元素与s1前j个元素是否匹配 

int main(){
	int t;
	cin >> t;
	char s1[MAX_SIZE], s2[MAX_SIZE];
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> (s1 + 1) >> (s2 + 1);
		int l1 = strlen(s1 + 1);
		int l2 = strlen(s2 + 1);
		dp[0][0] = 1;//1代表匹配
		if (s2[2] == '*') dp[2][0] = 1;
		for (int i = 1; i <= l2; ++i) {
			for (int j = 1; j <= l1; ++j) {
				if (s2[i] == '.' || s2[i] == s1[j]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
				} else if (s2[i] == '*') {
					if (dp[i - 2][j]) dp[i][j] = 1;//s2的第i-2 与s1的j匹配 ，* 可以让 i- 1出现0次 则当前也匹配 
					if (dp[i - 1][j]) dp[i][j] = 1;//s2的i-1 与 j匹配， *可以让i- 1出现一次，即*自己删除，则当前匹配 
					if (dp[i][j - 1] && s1[j] == s1[j - 1]) dp[i][j] = 1; 
				}
			}
		}
		if (dp[l2][l1]) {
			cout <<  "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
} 

/*
Sample Input
3
aa
a*
abb
a.*l
abb
aab
 

Sample Output
yes
yes
no
*/

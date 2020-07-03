#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 100

using namespace std;

int dp[MAX_SIZE][MAX_SIZE];

int scmp(char* s, char* s1) {
	int len1 = strlen(s + 1);
	int len2 = strlen(s1 + 1);
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			if (s[i] == '?' && dp[i - 1][j - 1]) {
				dp[i][j] = 1;
			} else if (s[i] == '*') {
				if (dp[i - 1][j - 1]) dp[i][j] = 1;
				if (dp[i - 1][j]) dp[i][j] = 1;
				if (dp[i][j - 1]) dp[i][j] = 1;
			} else if (s[i] == s1[j] && dp[i-1][j-1]) {
				dp[i][j] = 1;
			}
		}
	}
	return dp[len1][len2];
} 

int main() {
	char s[MAX_SIZE];
	int n;
	while (cin >> (s + 1)) {
		int count = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			char s1[MAX_SIZE];
			cin >> (s1 + 1);
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			if (scmp(s, s1)) count++;
		}
		cout << count << endl;
	}
	return 0;
}

/*
Sample Input
herbert
2
amazon
herbert

?ert*
2
amazon
herbert

*
2
amazon
anything

herbert?
2
amazon
herber
 

Sample Output
1
0 
2
0
*/

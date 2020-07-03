#include <string>
#include <iostream>
#include <cstring>

using namespace std;

bool CheckNum(char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}

bool Web(char* s) {
	int countdot = 0, countn = 0, sum = 0, dot = 0;//点总数，数字数量，连续数字和，连续点数 
	int len = strlen(s);
	if (s[len - 1] == '.')//如果最后一位为.是不合法的
        return false;
	for (int i = 0; i < len; ++i) {
		if (CheckNum(s[i])) {
			dot = 0;//把"."的数量重置 
			countn++;
			sum = sum * 10 + (s[i] - '0');
			if (countn > 3 || sum > 255 || sum < 0) {//连续超过三个数字或者当前的三位数比255大都是不符合的 
				return false;
			}
		} else if (s[i] == '.') {
			sum = 0;
			if (i == 0) return false;//第一个是.则不符合 
			countn = 0;//重置数字的数量
			dot++, countdot++;
			if (dot > 1) {//连续"."的数量超过1不符合 ,.的总数不超过3 
				return false;
			} 
		} else {
			return false;
		}
	}
	if (countdot != 3) return false;
	return true;
}

int main() {
	char s[105];
	while (gets(s)) {
		if (Web(s)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

/*
Sample Input
192.168.100.16
 

Sample Output
YES
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool isNum(char a) {//判断是否为数字
    if (a >= '0' && a <= '9')
        return true;
    else
        return false;
}

bool isHe(char* a) {
    int n = strlen(a);
    if (a[n - 1] == '.')//如果最后一位为.是不合法的
        return false;
    int j = 0;//j用来记录总的点数。
    int b[5] = {0};//数组b用来记录IP每位上的数字
    int numCount = 0, dotNum = 0;//numCount表示数字个数，dotNum表示点数
    for(int i = 0; i < n; i++) {
        if (isNum(a[i])) {
            b[j] = b[j] * 10 + (a[i] - '0');
            numCount++;
            if (numCount > 3)
                return false;
            dotNum = 0;
        } else if (a[i] == '.') {
            j++;
            dotNum++;
            numCount = 0;
            if (i == 0)//如果首位为.说明IP不合法
                return false;
            if (dotNum > 1)//如果有两位连续的.IP也是不合法的
                return false;
        }
        else {
        	return false;
		}
    }
    if (j != 3)//IP中的总点数不为3，IP不合法
        return false;
    for (int i = 0; i < 4; i++) {
        if (b[i] < 0 || b[i] > 255) {
        	return false;
		}
	}
    return true;
}

int main()
{

    char s[105];
    while (gets(s)) {//这里要用gets读入字符串，这样才能吞空格
        if (isHe(s)) {
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


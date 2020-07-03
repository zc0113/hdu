#include <string>
#include <iostream>
#include <cstring>

using namespace std;

bool CheckNum(char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}

bool Web(char* s) {
	int countdot = 0, countn = 0, sum = 0, dot = 0;//�������������������������ֺͣ��������� 
	int len = strlen(s);
	if (s[len - 1] == '.')//������һλΪ.�ǲ��Ϸ���
        return false;
	for (int i = 0; i < len; ++i) {
		if (CheckNum(s[i])) {
			dot = 0;//��"."���������� 
			countn++;
			sum = sum * 10 + (s[i] - '0');
			if (countn > 3 || sum > 255 || sum < 0) {//���������������ֻ��ߵ�ǰ����λ����255���ǲ����ϵ� 
				return false;
			}
		} else if (s[i] == '.') {
			sum = 0;
			if (i == 0) return false;//��һ����.�򲻷��� 
			countn = 0;//�������ֵ�����
			dot++, countdot++;
			if (dot > 1) {//����"."����������1������ ,.������������3 
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

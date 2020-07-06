#include <iostream>
#include <cstring>

using namespace std;

int arr[51], res[51];

void P(int n) {
	memset(res, 0, sizeof(res));
	for (int i = 0; i < n; ++i) {
		int k = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[i]) k++;
		}
		res[arr[i] - 1] = k;
	}
}

void I(int n) {
	memset(res, 0, sizeof(res));
	for (int i = 0; i < n; ++i) {
		int count = 0, j = 0;
		for (j; j < n; ++j) {//ͳ�Ƶ�ǰҪ���������֮ǰ���ж��ٿ�λ ������С��λ��ʼ����1��ǰ����2�������ʱ����1Ӧ�ò��뵽���������λ�ã� 2��ǰ����3��������2��ǰ��Ӧ����3����λ 
			if (count == arr[i] + 1) break;
			if (res[j] == 0) count++;
		}
		res[j - 1] = i + 1; 
	}
}

void Pr(int n) {
	for (int i = 0; i < n; ++i) {
		cout << res[i];
		if (i != n - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}	
} 

int main() {
	int n;
	while (cin >> n && n) {
		char c;
		cin >> c;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		if (c == 'P') {
			P(n);
			Pr(n);
		} else {
			I(n);
			Pr(n);
		}
	}
	return 0;
}
/*
Sample Input:
9
P 5 9 1 8 2 6 4 7 3
9
I 2 3 6 4 0 2 2 1 0
0

Sample Output:
2 3 6 4 0 2 2 1 0
5 9 1 8 2 6 4 7 3

*/

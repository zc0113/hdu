#include <iostream>
#include <cstdio>
#define MAX_SIZE 500005

using namespace std;

int a[MAX_SIZE], b[MAX_SIZE];
long long ans;

void MergeSort(int left, int right) {
	int i, j , k, mid;
	if (left < right) {
		mid = (left + right) >> 1;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		k = left;
		for (i = left, j = mid + 1; i <= mid && j <= right; ) {
			if (a[i] > a[j]) {
				b[k++] = a[j++];
				ans += mid - i + 1;//逆序对 
			} else {
				b[k++] = a[i++];
			}
		}
		while (i <= mid) {
			b[k++] = a[i++];
		}
		while (j <= right) {
			b[k++] = a[j++];
		}
		for (i = left; i <= right; ++i) {
			a[i] = b[i];
		}
	}
}

int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		ans = 0;
		MergeSort(1, n);
		cout << ans << endl;
	}
	return 0;
}
/*
Sample Input

5
9
1
0
5
4
3
1
2
3
0
Sample Output
..

6
0
*/

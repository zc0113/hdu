#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int flag = 1;
vector< vector<int> > chess;
vector< vector<int> > res;

bool isright(int r, int c, int temp) {
	int rr = (r / 3) * 3, cc = (c / 3) * 3;//小宫格的首坐标
	for (int i = 0; i < 9; ++i) {
		if (chess[r][i] == temp && i != c) return false;//行重复 
		if (chess[i][c] == temp && i != r) return false;//列重复
		if ((rr + (i / 3)) == r && (cc + (i % 3)) == c) {
			continue;
		} else if (chess[rr + (i / 3)][cc + (i % 3)] == temp) {
				return false;//小宫格重复 
			}
	} 
	return true;
}

bool solvesudu() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (chess[i][j] != 0) 
				continue; //0需要填入 
			for (int k = 1; k <= 9; ++k) {
				chess[i][j] = k;
				if (isright(i, j, k) && solvesudu()) {
					if (flag) {
						res.assign(chess.begin(), chess.end());
						flag = 0;
					}
					return true;
				}
				chess[i][j] = 0;
			}
			return false;
		}
	}
	return true;//没有空格
}

int main() {
	bool flag1 = false;
	string s;
	int count = 0;
	while (getline(cin, s)) {
		if (s.size() == 0 ) continue;
		vector<int> vec;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '?') {
				vec.push_back(0);
			} else if (s[i] > '0' && s[i] <= '9') {
				vec.push_back(s[i] - '0');
			}
		}
		chess.push_back(vec);//push一行 
		count++;
		if (count == 9) {
			solvesudu();
			flag = 1;
			if(flag1) printf("\n");//第二个解之前有空行 
			flag1 = true;
			for (int i = 0; i < 9; ++i) {
				cout << res[i][0];
				for (int j = 1; j < 9; ++j) {
					cout << " " << res[i][j];
				}
				cout << endl;
			}
			count = 0, chess.clear();//行数与数独重置 
		}
	}
	return 0;
}



/*
Sample Input
7 1 2 ? 6 ? 3 5 8
? 6 5 2 ? 7 1 ? 4
? ? 8 5 1 3 6 7 2
9 2 4 ? 5 6 ? 3 7
5 ? 6 ? ? ? 2 4 1
1 ? 3 7 2 ? 9 ? 5
? ? 1 9 7 5 4 8 6
6 ? 7 8 3 ? 5 1 9
8 5 9 ? 4 ? ? 2 3

7 1 2 ? 6 ? 3 5 8
? 6 5 2 ? 7 1 ? 4
? ? 8 5 1 3 6 7 2
9 2 4 ? 5 6 ? 3 7
5 ? 6 ? ? ? 2 4 1
1 ? 3 7 2 ? 9 ? 5
? ? 1 9 7 5 4 8 6
6 ? 7 8 3 ? 5 1 9
8 5 9 ? 4 ? ? 2 3


Sample Output
7 1 2 4 6 9 3 5 8
3 6 5 2 8 7 1 9 4
4 9 8 5 1 3 6 7 2
9 2 4 1 5 6 8 3 7
5 7 6 3 9 8 2 4 1
1 8 3 7 2 4 9 6 5
2 3 1 9 7 5 4 8 6
6 4 7 8 3 2 5 1 9
8 5 9 6 4 1 7 2 3

7 1 2 4 6 9 3 5 8
3 6 5 2 8 7 1 9 4
4 9 8 5 1 3 6 7 2
9 2 4 1 5 6 8 3 7
5 7 6 3 9 8 2 4 1
1 8 3 7 2 4 9 6 5
2 3 1 9 7 5 4 8 6
6 4 7 8 3 2 5 1 9
8 5 9 6 4 1 7 2 3
*/

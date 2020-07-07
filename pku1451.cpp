#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

struct node {
	int p;//记录频率
	char c;//记录当前节点对应 的字母
	node *next[26];
	int lev;//记录层数
};

node *root;
void insert(char *s, int p) {//插入一个单词
	node *por = root;
	for (; *s != '\0'; s++) {
		int d = *s-'a';
		if (por->next[d] == NULL) {
			por->next[d] = new node();
			por->next[d]->p = p;
			por->next[d]->c = *s;
		} else {
			por->next[d]->p += p;//计算当前字母的频率
		}
		por = por->next[d];
	}
}

void find(char *s, int e) {
	int table[10][4] = {{}, {}, {0,1,2,0}, {3,4,5,0}, {6,7,8,0}, {9,10,11,0}, {12,13,14,0}, {15,16,17,18}, {19,20,21,0}, {22,23,24,25}};//按键数字对应的字符映射表
	int max = 0;
	node *por = root, *cur = root, *nex;
	char word[101], ans[101];//word记录当前字母的前缀，ans记录频率最大的字母的前缀
	stack<node*> nd;
	nd.push(cur);
	cur->lev = -1;
	while (!nd.empty()) {
		cur = nd.top();
		nd.pop();
		if (cur->lev > -1) {
			word[cur->lev] = cur->c;//记录前缀
		}
		if (cur->lev == e) {
			if (cur->p >= max) {//等号不能省，当频率相同时，按字典序小的输出，而因为用栈压入的节点，所以字典序大的节点先访问了
				max = cur->p;
				for (int i = 0; i <= e; i++) { //到达对应输入串的层数且频率最大时，将当前word保存的前缀赋给ans
					ans[i] = word[i];
				}
			}
		} else {
			int n = (s[cur->lev + 1] == '7' || s[cur->lev + 1] == '9') ? 4 : 3;//注意7号键和9号键与其他数字键的区别
			for (int i = 0; i < n; i++) {
				int d = table[s[cur->lev + 1] - '0'][i];//s[cur->lev+1]表示下一层对应的数字，d表示数字键中映射的字母的序号
				nex = cur->next[d];
				if (nex != NULL) {
					nex->lev = cur->lev + 1;//下一节点的层数+1
					nd.push(nex);//压入栈
				}
			}
		}
	}
	if (max == 0) {
		cout << "MANUALLY" << endl;
	} else {
		ans[e + 1] = '\0';
		cout << ans << endl;//输入最大频率的前缀
	}
}

void del(node *por) {//清除字典树
	for (int i = 0; i < 26; i++) {
		if (por->next[i] != NULL) del(por->next[i]);
	}
	delete por;
}

int main() {
	int cas, k = 0, n, m, i, j, p;
	char word[105], str[105];
	cin >> cas;
	while (cas--) {
		cin >> n;
		root = new node();
		while (n--) {
			cin >> word >> p;
			insert(word, p);
		}
		cout << "Scenario #" << ++k << ':' << endl;
		cin >> m;
		while (m--) {
			cin >> str;
			int len = strlen(str) - 1;
			for (i = 0; i < len; i++) {
				find(str, i);
			}
			cout << endl;
		}
		cout << endl;
		del(root);
	}
	return 0;
}
/*
Sample Input

2
5
hell 3
hello 4
idea 8
next 8
super 3
2
435561
43321
7
another 5
contest 6
follow 3
give 13
integer 6
new 14
program 4
5
77647261
6391
4681
26684371
77771
Sample Output

Scenario #1:
i
id
hel
hell
hello

i
id
ide
idea


Scenario #2:
p
pr
pro
prog
progr
progra
program

n
ne
new

g
in
int

c
co
con
cont
anoth
anothe
another

p
pr
MANUALLY
MANUALLY
*/

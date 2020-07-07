#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

struct node {
	int p;//��¼Ƶ��
	char c;//��¼��ǰ�ڵ��Ӧ ����ĸ
	node *next[26];
	int lev;//��¼����
};

node *root;
void insert(char *s, int p) {//����һ������
	node *por = root;
	while (*s) {
		int d = *s-'a';
		if (por->next[d] == NULL) {
			por->next[d] = new node();
			por->next[d]->p = p;
			por->next[d]->c = *s;
		} else {
			por->next[d]->p += p;//���㵱ǰ��ĸ��Ƶ��
		}
		por = por->next[d];
		s++;
	}
}

void find(char *s, int e) {
	int table[10][4] = {{}, {}, {0,1,2,0}, {3,4,5,0}, {6,7,8,0}, {9,10,11,0}, {12,13,14,0}, {15,16,17,18}, {19,20,21,0}, {22,23,24,25}};//�������ֶ�Ӧ���ַ�ӳ���
	int max = 0;
	node *por = root, *cur = root, *nex;
	char word[101], ans[101];//word��¼��ǰ��ĸ��ǰ׺��ans��¼Ƶ��������ĸ��ǰ׺
	stack<node*> nd;
	nd.push(cur);
	cur->lev = -1;
	while (!nd.empty()) {
		cur = nd.top();
		nd.pop();
		if (cur->lev > -1) {
			word[cur->lev] = cur->c;//��¼ǰ׺
		}
		if (cur->lev == e) {
			if (cur->p >= max) {//�ȺŲ���ʡ����Ƶ����ͬʱ�����ֵ���С�����������Ϊ��ջѹ��Ľڵ㣬�����ֵ����Ľڵ��ȷ�����
				max = cur->p;
				for (int i = 0; i <= e; i++) { //�����Ӧ���봮�Ĳ�����Ƶ�����ʱ������ǰword�����ǰ׺����ans
					ans[i] = word[i];
				}
			}
		} else {
			int n = (s[cur->lev + 1] == '7' || s[cur->lev + 1] == '9') ? 4 : 3;//ע��7�ż���9�ż����������ּ�������
			for (int i = 0; i < n; i++) {
				int d = table[s[cur->lev + 1] - '0'][i];//s[cur->lev+1]��ʾ��һ���Ӧ�����֣�d��ʾ���ּ���ӳ�����ĸ�����
				nex = cur->next[d];
				if (nex != NULL) {
					nex->lev = cur->lev + 1;//��һ�ڵ�Ĳ���+1
					nd.push(nex);//ѹ��ջ
				}
			}
		}
	}
	if (max == 0) {
		cout << "MANUALLY" << endl;
	} else {
		ans[e + 1] = '\0';
		cout << ans << endl;//�������Ƶ�ʵ�ǰ׺
	}
}

void del(node *por) {//����ֵ���
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

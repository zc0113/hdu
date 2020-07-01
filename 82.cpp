#include<stdio.h>

typedef struct node{
	int xy[3][3];//8数码矩阵 
	int dir;
}node;

node sh[40001];
int count = 1, n = 0;//n记步数 

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void init(){
	printf("输入初始8数码3行3列矩阵:\n");
	int i, j;
	for (i = 0; i < 3; i++) { 
		for (j = 0; j < 3; j++) { 
			scanf("%d", &sh[0].xy[i][j]);
		}
	} 
	sh[0].dir = -1;
	printf("输入目标8数码3行3列矩阵:\n");
	for (i = 0; i < 3; i++) { 
		for (j = 0; j < 3; j++) { 
			scanf("%d", &sh[40000].xy[i][j]); 
		} 
	} 
	sh[40000].dir = -1;
}

//找出0的位置

int loction(int num){
	int i;
	for (i = 0; i < 9; i++) {
		if (sh[num].xy[i / 3][i % 3] == 0) { 
			return i;
		} 
	} 
}

//与目标矩阵比较
 
bool diff(node* sh1, node* sh2){
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (sh1->xy[i][j] != sh2->xy[i][j]) return false;
		}
	}
	return true;
}

void move(int num) {
	int loc = loction(num);
	int stand = sh[num].dir;
	//dir的0 1 2 3分别代表左 上 右 下
	if (loc / 3 != 0 && stand != 1) {//stand标记不重复移动 
		sh[count] = sh[num];
		swap(&sh[count].xy[loc / 3][loc % 3], &sh[count].xy[loc / 3 - 1][loc % 3]);
		sh[count].dir = 3;
		count++;
	}
	if (loc / 3 != 2 && stand != 3) {
		sh[count] = sh[num];
		swap(&sh[count].xy[loc / 3][loc % 3], &sh[count].xy[loc / 3 + 1][loc % 3]);
		sh[count].dir = 1;
		count++;
	} 
	if (loc % 3 != 0 && stand != 0) {
		sh[count] = sh[num];
		swap(&sh[count].xy[loc / 3][loc % 3], &sh[count].xy[loc / 3][loc % 3 - 1]);
		sh[count].dir = 2;
		count++;
	}
	if (loc % 3 != 2 && stand != 2) {
		sh[count] = sh[num];
		swap(&sh[count].xy[loc / 3][loc % 3], &sh[count].xy[loc / 3][loc % 3 + 1]);
		sh[count].dir = 0;
		count++;
	}
}

int search() {
	int i = 0, j = 0;
	while (1) {
		int count_m = count;
		for (j; j < count; ++j) {
			if (diff(&sh[j], &sh[40000])) {
				printf("经过%d次找到目标\n", n);
				return 0;
			}
		}
		for (i; i < count_m; ++i) {//将交换后的所有情况再次交换
			move(i);
		}
		n++;//每次0与周围的数都交换后加一步
	}
}

int main() {
	init();
	search();
}

//测试用例

/*

2 8 3

1 6 4

7 0 5

1 2 3

7 8 4

0 6 5

*/


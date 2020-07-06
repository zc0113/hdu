#include <map> 
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#define MAX_SIZE 30

using namespace std;

int main() {
	//string key, val;
	char english[MAX_SIZE], mouse[MAX_SIZE], s[MAX_SIZE];
	map<string, string> mymap;
	while (gets(s)) {
		if (!strlen(s)) break;
		sscanf(s, "%s%s", english, mouse);
		//key = Mouse;
		//val = English;
		//mymap[key] = val;
		mymap[mouse] = english;
		//cout << "my = " << mymap[key];
	}
	while (gets(s)) {
		if (mymap.find(s) != mymap.end()) {
			//printf("%s\n", mymap[s]);
			cout << mymap[s] << endl;
		} else {
			printf("eh\n");
		}
	}
	return 0;
}

/*
Sample Input
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
Output for Sample Input
cat
eh
loops
*/

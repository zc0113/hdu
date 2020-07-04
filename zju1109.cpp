#include <map> 
#include <iostream>
#include <string>
#include <cstring>
#define MAX_SIZE 25

using namespace std;

map<string, string> mymap;
string key, value;

int main() {
	char English[MAX_SIZE], Mouse[MAX_SIZE], s[MAX_SIZE];
	while (gets(s)) {
		if (!strlen(s)) break;
		sscanf(s, "%s %s", English, Mouse);
		key = Mouse;
		value = English;
		mymap[key] = value;
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

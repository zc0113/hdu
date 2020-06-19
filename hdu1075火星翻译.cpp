#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	string s, earth, mars;
	cin >> s;
	map<string, string> mymap;
	while (cin >> earth) {
		if (earth == "END") break;
		cin >> mars;
		mymap[mars] = earth;
	}
	cin >> s;
	getchar();
	string ls, word;
	while (getline(cin, ls)) {
		if (ls == "END") break;
		int len = ls.size();
		for (int i = 0; i < len; ++i) {
			if (isalpha(ls[i])) {//ÅÐ¶ÏÊÇ·ñÊÇÓ¢ÎÄ×ÖÄ¸ 
				word += ls[i];
				if (!isalpha(ls[i + 1])) {
					if (mymap[word] != "") {
						cout << mymap[word];
					} else {
						cout << word;
					}
					word.clear();
				}
			} else {
				cout << ls[i];
			}
		}
		cout << endl;
		ls.clear();
	}
	return 0;
}


/*Sample Input
START
from fiwo
hello difh
mars riwosf
earth fnnvk
like fiiwj
END
START
difh, i'm fiwo riwosf.
i fiiwj fnnvk!
END
 

Sample Output
hello, i'm from mars.
i like earth!
*/

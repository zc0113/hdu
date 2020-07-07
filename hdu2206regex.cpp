#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	string s, res;
	while (getline(cin, s)) {
	//	typedef basic_regex<char> regex;
		regex res("((25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))");
		regex_match(s, res) ? cout << "YES" : cout << "NO";
		cout << endl;
	}
	
	return 0;
}
/*
Sample Input
192.168.100.16
 

Sample Output
YES
*/

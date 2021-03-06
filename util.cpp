#include "util.h"
#include <iostream>
#include <sstream>

using namespace std;

char getFirstChar(set<string> s) {
	// get the first character of the set of a node.
	set<string>::iterator firstWord = s.begin(); // get the first word of the set.
	string word = *firstWord;
	return word[0];
}

void printSetContents(set<string> s){
	cout << "{ " ;
	for (set<string>::iterator it = s.begin(); it!= s.end(); ++it) cout << *it << " ";  
	cout << "}" << endl;
}

int compare(string str1, string str2) {
	// 1 if str1 > str2, -1 if str1 < str2, else 0 for equal case.
	if(str1.at(0) > str2.at(0)) return 1;
	if(str1.at(0) < str2.at(0)) return -1;

	return 0;
}

void tokenize(string s, vector<string> &setToBuild) {
	// Splites string "s" into tokens and each token is inserted
	// into the Set "setToBuild".
	stringstream ssin(s);
        string word;
	while(ssin >> word) {
		setToBuild.push_back(word);
	}
	
	setToBuild.push_back("");
}

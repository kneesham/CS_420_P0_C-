#include "util.h"
#include <iostream>
#include <sstream>

using namespace std;

char getFirstChar(set<string> s){
    // get the first character of the set of a node.
    set<string>::iterator firstWord = s.begin(); // get the first word of the set.
    string word = *firstWord;
    return word[0];
}

void indent(int depth) {
    for (int i = 0; i < 2 * depth; i++) cout << " ";
}

void printSetContents(set<string> s){
    cout << "{ " ;
	for (set<string>::iterator it = s.begin(); it!= s.end(); ++it){  
    	cout << *it << " ";  
	}
    cout << "}" << endl;
}

void printVectorContents(vector<string> s) {

	cout<< "Contents of vector are: " << endl;  
	for (vector<string>::iterator it = s.begin(); it!= s.end(); ++it){  
    	cout << *it << endl;  
	}
}

int compare(string str1, string str2) {
    if(str1.at(0) > str2.at(0)){
        return 1;
    }
    if(str1.at(0) < str2.at(0)) { // go left
        return -1;
    }
    return 0;
}

void tokenize(string s, vector<string> &setToBuild) {
	
    stringstream ssin(s);

    for (int i = 0; ssin.good(); i++){
		string word;
        ssin >> word;
        // cout << "ssin: " << ssin.;
		setToBuild.push_back(word);
    }
}
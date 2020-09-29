#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "tree.h"
#include "node.h"

using namespace std;

string readFromstdin() {
	char userInput[500];

	printf("\nPlease enter a string to build the tree with: ");
	fgets(userInput, 500, stdin);

	return  userInput;
}

string getTextFromFile(string fileName) {

		string line = "";
		string textToBuildTree = "";
		string fileWithExt = fileName + ".fs";

		ifstream file (fileWithExt);

		if(file.is_open()){
			while( getline(file, line) ){
				textToBuildTree += line;
			}
		}

	return textToBuildTree;	
}


void makeFileFromOutput(string name, node_t * root){
	fstream file; 
    file.open("out." + name, ios::out); 
    string line; 
  
    // Backup streambuffers of  cout 
    streambuf* stream_buffer_cout = cout.rdbuf(); 
    streambuf* stream_buffer_cin = cin.rdbuf(); 
  
    // Get the streambuffer of the file 
    streambuf* stream_buffer_file = file.rdbuf(); 
  
    // Redirect cout to file 
    cout.rdbuf(stream_buffer_file); 
  
    // printPreorder(root);

	if(name == "inorder") {
		printInorder(root);
	} else if(name == "postorder") {
		printPostorder(root);
	} else if(name == "preorder") {
		printPreorder(root);
	}  
    // Redirect cout back to screen 
    cout.rdbuf(stream_buffer_cout); 
    file.close(); 
}
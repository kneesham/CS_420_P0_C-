#include <string>
#include <fstream>
#include <iostream>
#include "tree.h"
#include "node.h"

using namespace std;

string readFromstdin() {
	// Reads user input/file redirection from stdin.
	char userInput[500];

	printf("\nPlease enter a string to build the tree with: ");
	fgets(userInput, 500, stdin);

	return userInput;
}

string getTextFromFile(string fileName) {
	// Gets the text from the file requested if it exists...
	string line = "";
	string textToBuildTree = "";
	string fileWithExt = fileName + ".fs";
	ifstream file;
	file.open(fileWithExt.c_str());

	if(file.is_open()){
		while( getline(file, line) ){
			textToBuildTree += line;
		}
	}

	return textToBuildTree;	
}

void makeFileFromOutput(string name, node_t * root){
	// Generates a given file based on the "name" given to the function then 
	// captures the output of the called function which is related to the file name.

	fstream file;
	string fileWithExt = "out." + name; 
	file.open(fileWithExt.c_str(),  ios_base::out); 
	string line; 

	streambuf* stream_buffer_cout = cout.rdbuf(); 
	streambuf* stream_buffer_cin = cin.rdbuf(); 
        // Backup streambuffers of "cout"
        
	streambuf* stream_buffer_file = file.rdbuf(); 
	// Get the streambuffer of the file
	
	cout.rdbuf(stream_buffer_file); 
	// Redirect "cout" to file

	if(name == "inorder") {
		printInorder(root);
	} else if(name == "postorder") {
		printPostorder(root);
	} else if(name == "preorder") {
		printPreorder(root);
	}
  
	cout.rdbuf(stream_buffer_cout); 
	// Redirect cout back to screen
	
	file.close(); 
}

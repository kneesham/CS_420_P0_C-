#include <iostream>
#include <string>
#include "argHandler.h"
#include "fileManager.h"
#include "node.h"
#include "tree.h"

// Helper functions.
void printTrees(node_t *);
void makeFiles(node_t *, string);

using namespace std;

int main(int argc, char * argv[]) {
	
	// A string that will be broken up into "words" and used to build the tree.
	string textForTree;
	string fileName;

	if(hasProperArgs(argc)){
		// read from cammand line argument filename
		fileName = argv[argc - 1];
		textForTree = getTextFromFile(fileName);
	} else {
		// get input from keyboard.
		textForTree = readFromstdin();
		fileName = "";
	}

	
	// Building the tree with text received.
	node_t * root = buildTree(textForTree);
	
	// Generate out.* files and display tree to console.
	printTrees(root);
	makeFiles(root, fileName);
	return 0;
}

void printTrees(node_t * root){
	// helper function to reduce size of main.

	cout << "\nPRINTING THE TREE POST-ORDER"  << endl;
	printPostorder(root);

	cout << "\nPRINTING THE TREE IN-ORDER"  << endl;
	printInorder(root);

	cout << "\nPRINTING THE TREE PRE-ORDER"  << endl;
	printPreorder(root);
}

void makeFiles(node_t * root, string filename){
	// helper function
	makeFileFromOutput(filename, "preorder", root);
	makeFileFromOutput(filename, "inorder", root);
	makeFileFromOutput(filename, "postorder", root);
}

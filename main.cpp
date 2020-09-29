// Usage P0 [file] - file is an optional argument.
// P0 		 // read from the keyboard until simulated EOF
// P0 < somefile // same as above except redirecting from somefile instead of keyboard, this tests keyboard input
// P0 somefile   // read from somefile.fs

#include <iostream>
#include <string>
#include "argHandler.h"
#include "fileManager.h"
#include "node.h"
#include "tree.h"

void printTrees(node_t *);
void makeFiles(node_t *);

using namespace std;

int main(int argc, char * argv[]) {
	// TODO: Process command arguments, set up file to work regardless of source,
	//  check if file readable, set the basename for the output file, etc.
	string textForTree;
	
	if(hasProperArgs(argc)){
		// read from cammand line argument filename
        string fileName(argv[argc - 1]);
        textForTree = getTextFromFile(fileName);
	}
	else {
		// get input from keyboard.
		textForTree = readFromstdin();
	}

	node_t * root = buildTree(textForTree);
	
	printTrees(root);
	makeFiles(root);

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
void makeFiles(node_t * root){
	// helper function
	makeFileFromOutput("preorder", root);
	makeFileFromOutput("inorder", root);
	makeFileFromOutput("postorder", root);
}
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

#include "node.h"
#include "util.h"

using namespace std;

void printPreorder(node_t * nd){

    if (nd == NULL){
        return;
    }
    
    /* display node data */
    indent(nd->node_depth);
    cout << getFirstChar(nd->words) << ": ";
    printSetContents(nd->words);
 
    printPreorder(nd->left);
    printPreorder(nd->right);

}
void printInorder(node_t * nd){
    // implement me!
    if (nd == NULL){
        return;
    }
    
    printPreorder(nd->left);

    /* display node data */
    indent(nd->node_depth);
    cout << getFirstChar(nd->words) << ": ";
    printSetContents(nd->words);
 

    printPreorder(nd->right);

}
void printPostorder(node_t * nd){

    if (nd == NULL){
        return;
    }
    // traverse.
    printPostorder(nd->left);
    printPostorder(nd->right);

    // print node data here.
    indent(nd->node_depth);
    cout << getFirstChar(nd->words) << ": ";
    printSetContents(nd->words);

}


node_t * createNode(string word, int depth){
    
    node_t *new_node = new node_t(word, depth);
    new_node->left = NULL;
    new_node->right = NULL;

    if(new_node == NULL){
        fprintf (stderr, "Out of memory!!! (create_node)\n");
        exit(1);
    }
    return new_node;
}

node_t * insertNode(node_t * root, string word) {

    if(root == NULL){
        root = createNode(word, 0);
    }
    else {
        int is_left  = -1;
        int r        = 0;
        int node_depth = 0;
        node_t * cursor = root;
        node_t * prev   = NULL;

 
        while(cursor != NULL) {
            set<string>::iterator firstWord = cursor->words.begin(); // get the first word of the set.
            string word1 = *firstWord;
            r = compare(word, word1);

            prev = cursor;
            if(r < 0) {
                is_left = 1;
                cursor = cursor->left;
            }
            else if(r > 0) {
                is_left = 0;
                cursor = cursor->right;
            }
            else if(r == 0){
                cursor->words.insert(word);
                is_left = -1;
                break;
            }
            node_depth++;
        }

        if(is_left == 1){
            prev->left = createNode(word, node_depth);
        }
        else if(is_left == 0) {
            prev->right = createNode(word, node_depth);
        }

    }
    return root;
}


node_t * buildTree(string text) {

    node_t * root = NULL;
    vector<string> tokens; // tokens are words from the string, or anything that isn't whitespace.

    tokenize(text, tokens); // splitting the "text" variable into a set of unordered words
    
    for (int i = 0; i < tokens.size() - 1; i++){
        root = insertNode(root, tokens.at(i));
    }
    
    // // display_tree(root);
    // printInorder(root);
    return root;
}



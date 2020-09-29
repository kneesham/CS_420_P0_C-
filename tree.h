
#ifndef TREE_H 
#define TREE_H  
#include "node.h"

node_t * buildTree(std::string);
void printPreorder(node_t *);
void printInorder(node_t *);
void printPostorder(node_t *); 


#endif


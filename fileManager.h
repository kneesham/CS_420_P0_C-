#ifndef FILEMANAGER_H 
#define FILEMANAGER_H
#include "node.h"

std::string readFromstdin();
std::string getTextFromFile(std::string);
void makeFileFromOutput(std::string, node_t * );

#endif

#ifndef UTIL_H 
#define UTIL_H  
#include <string>
#include <unordered_set>
#include <vector>
#include <set>
void indent(int);
void printSetContents(std::set<std::string>);
void tokenize(std::string, std::vector<std::string>&);
int compare(std::string, std::string);
char getFirstChar(std::set<std::string>);
#endif

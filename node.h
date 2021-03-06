#ifndef NODE_H
#define NODE_H
#include <string>
#include <set>

using namespace std;

typedef struct node_t {
	set<string> words;          // string of words at the node.
	struct node_t * left;       // for smaller words.
	struct node_t * right;      // for bigger words.
	int node_depth;             // to track the depth of a node.

	node_t(string word, int depth) {
		words.insert(word);
		left = NULL;
		right = NULL;
		node_depth = depth;
	}
} node_t;

#endif

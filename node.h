/*Ian Lofton Green
 *CS428
 *Project 2 
*/

#ifndef NODE_H
#define NODE_H

#include "token.h"
#include <set>
#include <string>
#include <vector>

using namespace std;

struct node_t {
	int level;
	int tkSize;
	string tag;
	vector<Token> tokens;
	struct node_t *n1, *n2, *n3, *n4;
};

#endif

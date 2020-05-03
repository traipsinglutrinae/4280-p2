/*Ian Lofton Green
 *CS428
 *Project 2 
*/

#include <iostream>
#include <string>
#include "testTree.h"

using namespace std;

void preOrder(node_t *node, int level) {
	string relativeLine;
	if (node == NULL) {
		return;
	}
	for (int i = 0; i < level; i++) {
		relativeLine.append("  ");
	}
	relativeLine.append(node->tag);
	relativeLine.append("  ");
	for (int i = 0; i < node->tokens.size(); i++) {
		relativeLine.append(node->tokens[i].description);
		if (((i + 1) != node->tokens.size()) && (node->tokens[i].ID != opTk)) {
			relativeLine.append("  ");
		}
		relativeLine.append("  ");
	}
	cout << relativeLine << endl;
	preOrder(node->n1, level+1);
	preOrder(node->n2, level+1);
	preOrder(node->n3, level+1);
	preOrder(node->n4, level+1);
}

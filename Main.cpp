#include "SplayTree.h"
void main() {
	Node* n = new Node(1);
	SplayTree* sp = new SplayTree(n);
	int i = 2;
	while (i < 6) {
		sp->Insert(i);
		i++;
	}
	sp->Find(2);
	sp->Insert(7);
	sp->Remove(2);
}
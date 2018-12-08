#pragma once
#include "Tree.h"
class SplayTree: Tree {
	Node* root;
public:
	SplayTree(Node* node): root(node) {
	};
	Node* getRoot() {
		return root;
	}
	/***********************************************************/
	virtual  Node* Find(int key);
	virtual void Insert(int key);
	virtual void Remove(int key);
	void Splay(Node* u);
	SplayTree Split(int k);
	void Merge(SplayTree u);
	/***********************************************************/
private:
	void Zig(Node* u);
	void ZigZig(Node* u);
	void ZigZag(Node* u);
	void Zag(Node* u);
	void ZagZag(Node* u);
	void ZagZig(Node* u);
};
#include "SplayTree.h"

//Left
void SplayTree::Zig(Node* u) {
	Node* buf = root;
	buf->setLeft(u->getRight());
	buf->setParent(u);

	u->setParent(nullptr);
	u->setRight(buf);

}
//LeftLeft
void SplayTree::ZigZig(Node* u) {
	Node* parent = u->getParent();
	Node* grandparent = parent->getParent();
	u->setParent(grandparent->getParent());

	Node* buf = grandparent;
	buf->setLeft(parent->getRight());
	buf->setParent(parent);

	Node* buf1 = parent;
	buf1->setLeft(u->getRight());
	buf1->setParent(u);

	buf1->setRight(buf);
	u->setRight(buf1);
}
//LeftRight
void SplayTree::ZigZag(Node* u) {
	Node* parent = u->getParent();
	Node* grandparent = parent->getParent();
	u->setParent(grandparent->getParent());

	Node* buf = grandparent;
	buf->setLeft(u->getRight());
	buf->setParent(u);

	Node* buf1 = parent;
	buf1->setRight(u->getLeft());
	buf1->setParent(u);

	u->setLeft(buf1);
	u->setRight(buf);
}
//Right
void SplayTree::Zag(Node* u) {
	Node* buf = root;
	buf->setRight(u->getLeft());
	buf->setParent(u);

	u->setParent(nullptr);
	u->setLeft(buf);
}
//RightRight
void SplayTree::ZagZag(Node* u) {

	Node* parent = u->getParent();
	Node* grandparent = parent->getParent();
	u->setParent(grandparent->getParent());

	Node* buf = grandparent;
	buf->setRight(parent->getLeft());
	buf->setParent(parent);

	Node* buf1 = parent;
	buf1->setRight(u->getLeft());
	buf1->setParent(u);

	buf1->setLeft(buf);
	u->setLeft(buf1);

}
//RightLeft
void SplayTree::ZagZig(Node* u) {
	Node* parent = u->getParent();
	Node* grandparent = parent->getParent();
	u->setParent(grandparent->getParent());

	Node* buf = grandparent;
	buf->setRight(u->getLeft());
	buf->setParent(u);

	Node* buf1 = parent;
	buf1->setLeft(u->getRight());
	buf1->setParent(u);

	u->setLeft(buf);
	u->setRight(buf1);
}



void SplayTree::Splay(Node* u) {
	Node* parent = nullptr;
	Node* grandparent = nullptr;

	while (true) {
		if (u->getParent() == nullptr) {
			root = u;
			return;
		}
		parent = u->getParent();
		grandparent = parent->getParent();

		if (grandparent == nullptr) {
			if (parent->getRight() == u) {
				Zag(u);
			}
			else {
				Zig(u);
			}
		}
		else {
			if (grandparent->getRight() == parent) {
				if (parent->getRight() == u) {
					ZagZag(u);
				}
				else {
					ZagZig(u);
				}

			}
			else {
				if (parent->getRight() == u) {
					ZigZag(u);
				}
				else {
					ZigZig(u);
				}

			}
		}
	}

}

Node* SplayTree::Find(int key) {
	Node* curr = root;
	int rkey = 0;
	int lkey = 0;
	while (true)
	{
		if (curr->getRight() != nullptr) {
			rkey = curr->getRight()->getKey();
			if (key >= rkey) {
				curr = curr->getRight();
				continue;
			}
		}
		if (curr->getLeft() != nullptr) {
			lkey = curr->getLeft()->getKey();
			if (key <=  lkey) {
				curr = curr->getLeft();
				continue;
			}
		}
		Splay(curr);
		return curr;
	}
}

SplayTree SplayTree::Split(int k) {
	Node* res = Find(k);
	Splay(res);
	return SplayTree(root->getRight());

}

void SplayTree::Merge(SplayTree u) {
	Node* curr = getRoot();
	while (curr->getLeft() != nullptr) {
		curr = curr->getLeft();
	}
	Splay(curr);
	(getRoot())->setRight(u.getRoot());
}

void SplayTree::Remove(int k) {
	Node* curr = Find(k);
	Node* left = nullptr;
	Node* right = nullptr;
	Splay(curr);
	left = curr->getLeft();
	right = curr->getRight();

	if (curr->existLeft() && curr->existRight()) {
		left->setParent(nullptr);
		right->setParent(nullptr);
		root = left;
		Merge(SplayTree(right));
	}
	else {
		if (curr->existLeft()) {
			left->setParent(nullptr);
			root = left;
		}
		if (curr->existRight()) {
			right->setParent(nullptr);
			root = right;
		}
	}
	root->setParent(nullptr);
	delete curr;
}
void SplayTree::Insert(int key) {
	Node* curr = Find(key);
	Node* node = new Node(key);
	if (key > curr->getKey()) {
		Node* right = curr->getRight();
		node->setParent(curr);
		curr->setRight(node);
		node->setRight(right);
		if (right != nullptr)
		{
			right->setParent(node);
		}
	}
	else{
		Node* left = curr->getLeft();
		node->setParent(curr);
		curr->setLeft(node);
		node->setLeft(left);
		if (left != nullptr)
		{
			left->setParent(node);
		}
	}
	Splay(node);
}
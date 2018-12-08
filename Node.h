#pragma once
class Node {
	Node *parent;
	Node *right_child;
	Node *left_child;
	int key;
public:
	Node(Node* par, Node* right, Node* left, int nkey) {
		parent = par;
		right_child = right;
		left_child = left;
		key = nkey;
	}

	Node(int nkey) {
		parent = nullptr;
		right_child = nullptr;
		left_child = nullptr;
		key = nkey;
	}

	Node* getParent() {
		return parent;
	}
	Node* getRight() {
		return right_child;
	}
	Node* getLeft() {
		return left_child;
	}

	int getKey() {
		return key;
	}

	bool existRight() {
		if (getRight() != nullptr) {
			return true;
		}
		return false;
	}

	bool existLeft() {
		if (getLeft() != nullptr) {
			return true;
		}
		return false;
	}
	
	void setParent(Node* node) {
		parent = node;
	}
	void setRight(Node* node) {
		right_child = node;
	}
	void setLeft(Node* node) {
		left_child = node;
	}

};
#pragma once
#include "Node.h"
class Tree {
public:
	virtual  Node* Find(int key) = 0;
	virtual void Insert(int key) = 0;
	virtual void Remove(int key) = 0;
};
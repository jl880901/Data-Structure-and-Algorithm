/*
 * RBTreeNode.h
 *
 *  Created on: 2017Äê5ÔÂ1ÈÕ
 *      Author: lajiao
 */

#ifndef SRC_RBTREENODE_H_
#define SRC_RBTREENODE_H_

#include <iostream>

using namespace std;

enum rbcolor {
	red, black
};

template<class T>
class RBTreeNode {
public:
	RBTreeNode();
	RBTreeNode(RBTreeNode<T> *left, RBTreeNode<T> *right, RBTreeNode<T> *par,
			rbcolor rbc, T k);
	virtual ~RBTreeNode();
	void SetLeftChild(RBTreeNode<T> *left);
	void SetRightChild(RBTreeNode<T> *right);
	void SetParent(RBTreeNode<T> *par);
	void SetColor(rbcolor rbc);
	void SetKey(T k);

	rbcolor getColor() const {
		return color;
	}

	T getKey() const {
		return key;
	}

	RBTreeNode<T>* getLeftChild() const {
		return leftChild;
	}

	RBTreeNode<T>* getParent() const {
		return parent;
	}

	RBTreeNode<T>* getRightChild() const {
		return rightChild;
	}

	T VisitNode() {
		cout << this->key << " ";
		return this->key;
	}

private:
	T key;
	RBTreeNode<T> *leftChild;
	RBTreeNode<T> *rightChild;
	RBTreeNode<T> *parent;
	rbcolor color;
};

#endif /* SRC_RBTREENODE_H_ */

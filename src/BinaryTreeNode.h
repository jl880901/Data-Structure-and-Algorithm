/*
 * BinaryTreeNode.h
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */
#include <cstddef>
#include <iostream>

using namespace std;

#ifndef SRC_TREENODE_H_
#define SRC_TREENODE_H_

template<class T> class BinaryTreeNode {
	//friend class BinaryTree<T>;
public:
	BinaryTreeNode();
	BinaryTreeNode(T x) {
		this->val = x;
		this->left = nullptr;
		this->right = nullptr;
	}
	virtual ~BinaryTreeNode();

	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
	T GetVal() const;
	BinaryTreeNode<T>* GetLeftChild() const;
	BinaryTreeNode<T>* GetRightChild() const;

	void SetLeftChild(BinaryTreeNode<T> *l);
	void SetRightChild(BinaryTreeNode<T> *r);
	void SetValue(const T& x);
	T VisitNode();
private:
	T val;
};

#endif /* SRC_TREENODE_H_ */

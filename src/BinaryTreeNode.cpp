/*
 * BinaryTreeNode.cpp
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */

#include "BinaryTreeNode.h"

template<class T> BinaryTreeNode<T>::BinaryTreeNode() {
	// TODO Auto-generated constructor stub
	this->left = NULL;
	this->right = NULL;
}

template<class T> BinaryTreeNode<T>::~BinaryTreeNode() {
	// TODO Auto-generated destructor stub
}

template<class T> T BinaryTreeNode<T>::GetVal() const{
	return this->val;
}

template<class T> BinaryTreeNode<T>* BinaryTreeNode<T>::GetLeftChild() const{
	return this->left;
}

template<class T> BinaryTreeNode<T>* BinaryTreeNode<T>::GetRightChild() const{
	return this->right;
}

template<class T> void BinaryTreeNode<T>::SetLeftChild(BinaryTreeNode<T> *l){
	this->left = l;
}

template<class T> void BinaryTreeNode<T>::SetRightChild(BinaryTreeNode<T> *r){
	this->right = r;
}

template<class T> void BinaryTreeNode<T>::SetValue(const T &x){
	this->val = x;
}

template<class T> T BinaryTreeNode<T>::VisitNode(){
	cout << this->val << " " ;
	return this->val;
}

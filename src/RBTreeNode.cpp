/*
 * RBTreeNode.cpp
 *
 *  Created on: 2017Äê5ÔÂ1ÈÕ
 *      Author: lajiao
 */

#include "RBTreeNode.h"

template<class T> RBTreeNode<T>::RBTreeNode() {
	// TODO Auto-generated constructor stub
	this->leftChild = nullptr;
	this->rightChild = nullptr;
	this->color = black;
	this->parent = nullptr;
}

template<class T> RBTreeNode<T>::RBTreeNode(RBTreeNode<T> *left, RBTreeNode<T> *right, RBTreeNode<T> *par, rbcolor rbc, T k){
	this->leftChild = left;
	this->rightChild = right;
	this->color = rbc;
	this->parent = par;
	this->key = k;
}

template<class T> RBTreeNode<T>::~RBTreeNode() {
	// TODO Auto-generated destructor stub
}

template<class T> void RBTreeNode<T>::SetLeftChild(RBTreeNode<T> *left){
	this->leftChild = left;
}

template<class T> void RBTreeNode<T>::SetRightChild(RBTreeNode<T> *right){
	this->rightChild = right;
}

template<class T> void RBTreeNode<T>::SetColor(rbcolor rbc){
	this->color = rbc;
}

template<class T> void RBTreeNode<T>::SetParent(RBTreeNode<T> *par){
	this->parent = par;
}

template<class T> void RBTreeNode<T>::SetKey(T k){
	this->key = k;
}

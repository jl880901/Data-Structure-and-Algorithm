/*
 * RBTree.cpp
 *
 *  Created on: 2017Äê5ÔÂ2ÈÕ
 *      Author: lajiao
 */

#include "RBTree.h"

template<class T> RBTree<T>::RBTree() {
	// TODO Auto-generated constructor stub
	this->root = nullptr;
	this->sentinel = new RBTreeNode<T>(nullptr, nullptr, nullptr, black, 0);
}

template<class T> RBTree<T>::~RBTree() {
	// TODO Auto-generated destructor stub
}

template<class T> void RBTree<T>::CreateRedBlackTree(vector<T> data) {
	cout << "Creating RBTree ..." << endl;
	for (auto element : data) {
		this->InsertNode(element);
	}
	cout << "RBTree has been created." << endl;
}

template<class T> void RBTree<T>::InsertNode(T key) {
	RBTreeNode<T> *cur = this->root, *tempparent = this->sentinel;
	RBTreeNode<T> *newnode = new RBTreeNode<T>(this->sentinel, this->sentinel,
			this->sentinel, red, key);
	while (cur && cur != this->sentinel) {
		tempparent = cur;
		if (cur->getKey() > key)
			cur = cur->getLeftChild();
		else
			cur = cur->getRightChild();
	}
	newnode->SetParent(tempparent);
	if (tempparent == this->sentinel) // root is null
		this->root = newnode;
	else if (key < tempparent->getKey())
		tempparent->SetLeftChild(newnode);
	else
		tempparent->SetRightChild(newnode);

	this->RBTreeInsertFixup(newnode);
}

template<class T> void RBTree<T>::RBTreeInsertFixup(RBTreeNode<T> * node) {
	while (node->getParent()->getColor() == red) {
		RBTreeNode<T> *grandparent = node->getParent()->getParent();
		if (grandparent->getLeftChild() == node->getParent()) {
			RBTreeNode<T> *uncle = grandparent->getRightChild();
			if (uncle && uncle->getColor() == red) {
				node->getParent()->SetColor(black);
				uncle->SetColor(black);
				grandparent->SetColor(red);
				node = grandparent;
			} else {
				if (node == node->getParent()->getRightChild()) {
					node = node->getParent();
					this->LeftRotate(node);
				}
				node->getParent()->SetColor(black);
				grandparent->SetColor(red);
				this->RightRotate(grandparent);
			}
		} else {
			RBTreeNode<T> *uncle = grandparent->getLeftChild();
			if (uncle && uncle->getColor() == red) {
				node->getParent()->SetColor(black);
				uncle->SetColor(black);
				grandparent->SetColor(red);
				node = grandparent;
			} else {
				if (node == node->getParent()->getLeftChild()) {
					node = node->getParent();
					this->RightRotate(node);
				}
				node->getParent()->SetColor(black);
				grandparent->SetColor(red);
				this->LeftRotate(grandparent);
			}
		}
	}
	root->SetColor(black);
}

template<class T> void RBTree<T>::DeleteNode(RBTreeNode<T> *node) {

}

template<class T> void RBTree<T>::LeftRotate(RBTreeNode<T> *node) {
	RBTreeNode<T> *grandParent = node->getParent();
	RBTreeNode<T> *rightChild = node->getRightChild();

	node->SetRightChild(rightChild->getLeftChild());
	if (rightChild->getLeftChild() != this->sentinel)
		rightChild->getLeftChild()->SetParent(node);
	rightChild->SetParent(grandParent);

	if (grandParent == this->sentinel)
		this->root = rightChild;
	else {
		if (node == grandParent->getLeftChild())
			grandParent->SetLeftChild(rightChild);
		else
			grandParent->SetRightChild(rightChild);
	}

	rightChild->SetLeftChild(node);
	node->SetParent(rightChild);
}

template<class T> void RBTree<T>::RightRotate(RBTreeNode<T> *node) {
	RBTreeNode<T> *grandParent = node->getParent();
	RBTreeNode<T> *leftChild = node->getLeftChild();

	node->SetLeftChild(leftChild->getRightChild());
	if (leftChild->getRightChild() != this->sentinel)
		leftChild->getRightChild()->SetParent(node);

	if (grandParent == this->sentinel)
		this->root = leftChild;
	else {
		if (node == grandParent->getLeftChild())
			grandParent->SetLeftChild(leftChild);
		else
			grandParent->SetRightChild(leftChild);
	}

	leftChild->SetRightChild(node);
	node->SetParent(leftChild);
}

template<class T> RBTreeNode<T>* RBTree<T>::Find(T& key){
	RBTreeNode<T> * res = nullptr;
	RBTreeNode<T> * cur = this->root;
	while(cur && cur != this->sentinel){
		if(cur->getKey() < T)
			cur = cur->getRightChild();
		else if(cur->getKey() > T)
			cur = cur->getLeftChild();
		else
			return cur;
	}
	return res;
}

template<class T> RBTreeNode<T>* RBTree<T>::DeleteNode(RBTreeNode<T> * node){

}

template<class T> void RBTree<T>::PreOrder(RBTreeNode<T> * root) {
	if (!root || root == this->sentinel)
		return;
	root->VisitNode();
	this->PreOrder(root->leftChild);
	this->PreOrder(root->rightChild);
}

template<class T> void RBTree<T>::InOrder(RBTreeNode<T> * root) {
	if (!root || root == this->sentinel)
		return;
	this->InOrder(root->getLeftChild());
	root->VisitNode();
	this->InOrder(root->getRightChild());
}

template<class T> void RBTree<T>::PostOrder(RBTreeNode<T> * root) {
	if (!root || root == this->sentinel)
		return;
	this->PostOrder(root->leftChild);
	this->PostOrder(root->rightChild);
	root->VisitNode();
}

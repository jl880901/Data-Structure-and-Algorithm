/*
 * BinaryTree.cpp
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */

#include <queue>
#include "BinaryTree.h"
#include <stack>

using namespace std;

template<class T> BinaryTree<T>::BinaryTree() {
	// TODO Auto-generated constructor stub
	this->root = nullptr;
}

template<class T> BinaryTree<T>::~BinaryTree() {
	// TODO Auto-generated destructor stub
}

template<class T> void BinaryTree<T>::CreateTree() {
	this->root = nullptr;
}

template<class T> void BinaryTree<T>::CreateCompleteBinaryTreeforDemo(
		vector<T> data) {
	int size = data.size();
	int currentnum = 0;
	queue<BinaryTreeNode<T>*> q;

	if (size > 0) { // contains at least 1 node
		this->root = new BinaryTreeNode<T>(data[currentnum++]);
		q.push(this->root);
	}
	while (!q.empty()) {
		BinaryTreeNode<T>* ptr = q.front();
		q.pop();
		if (currentnum < size) {
			ptr->left = new BinaryTreeNode<T>(data[currentnum++]);
			q.push(ptr->left);
		}
		if (currentnum < size) {
			ptr->right = new BinaryTreeNode<T>(data[currentnum++]);
			q.push(ptr->right);
		}
	}
}

template<class T> void BinaryTree<T>::CreateTreeHelper(const T& val,
		BinaryTreeNode<T> & leftChildTree, BinaryTreeNode<T> & rightChildTree) {
	this->root->setValue(val);
	this->root->setLeftChild(&leftChildTree);
	this->root->setRightChild(&rightChildTree);
}

template<class T> void BinaryTree<T>::PreOrder(BinaryTreeNode<T> * root) {
	if (!root)
		return;
	root->VisitNode();
	this->PreOrder(root->left);
	this->PreOrder(root->right);
}

template<class T> void BinaryTree<T>::PreOrderWithoutRecursion(BinaryTreeNode<T> * root) {
	if(!root)
		return;

	stack<BinaryTreeNode<T> *> sta;
	sta.push(root);
	while(!sta.empty()){
		BinaryTreeNode<T> * cur = sta.top();
		sta.pop();
		cur->VisitNode();
		if(cur->right)
			sta.push(cur->right);
		if(cur->left)
			sta.push(cur->left);
	}
}

template<class T> void BinaryTree<T>::PostOrder(BinaryTreeNode<T> * root) {
	if (!root)
		return;
	this->PostOrder(root->left);
	this->PostOrder(root->right);
	root->VisitNode();
}

template<class T> void BinaryTree<T>::PostOrderWithoutRecursion(BinaryTreeNode<T> * root){
	if (!root)
		return;
	stack<BinaryTreeNode<T> *> sta;
	BinaryTreeNode<T> *temp = nullptr;

	sta.push(root);
	while(!sta.empty()){
		BinaryTreeNode<T> *cur = sta.top();
		if((cur->left == nullptr && cur->right == nullptr) || (temp && (cur->left == temp || cur->right == temp))){
			cur->VisitNode();
			sta.pop();
			temp = cur;
		}
		else{
			if(cur->right)
				sta.push(cur->right);
			if(cur->left)
				sta.push(cur->left);
		}
	}
}

template<class T> void BinaryTree<T>::InOrder(BinaryTreeNode<T> * root) {
	if (!root)
		return;
	this->InOrder(root->left);
	root->VisitNode();
	this->InOrder(root->right);
}

template<class T> void BinaryTree<T>::InOrderWithoutRecursion(BinaryTreeNode<T> * root){
	if (!root)
		return;
	stack<BinaryTreeNode<T> *> sta;
	BinaryTreeNode<T> * temp = root; // be used to judge if left child tree has been visited
	while(!sta.empty() || temp){
		if(temp){
			sta.push(temp);
			temp = temp->left;
		}
		else{
			BinaryTreeNode<T> * cur = sta.top();
			sta.pop();
			cur->VisitNode();
			temp = cur->right;
		}
	}
}

template<class T> void BinaryTree<T>::LevelOrder(BinaryTreeNode<T> * root) {
	if (!root)
		return;

	queue<BinaryTreeNode<T>*> que;
	que.push(root);
	while (!que.empty()) {
		BinaryTreeNode<T>* cur = que.front();
		que.pop();
		cur->VisitNode();
		if (cur->left)
			que.push(cur->left);
		if (cur->right)
			que.push(cur->right);
	}
}

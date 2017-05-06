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

template<class T> BinarySearchTree<T>::BinarySearchTree(){
	this->root = nullptr;
}

template<class T> BinarySearchTree<T>::~BinarySearchTree(){

}

template<class T> void BinarySearchTree<T>::CreateBinarySearchTree(vector<T> data){
	for(auto element : data){
		this->InsertNode(element);
	}
}

template<class T> void BinarySearchTree<T>::InsertNode(T processingNode){
	if(this->root == nullptr){
		this->root = new BinaryTreeNode<T>(processingNode);
		return;
	}

	BinaryTreeNode<T> *cur = this->root, *pre;
	while(cur){
		pre = cur;
		if(cur->GetVal() < processingNode){
			cur = cur->GetRightChild();
			if(!cur){
				cur = new BinaryTreeNode<T>(processingNode);
				pre->right = cur;
			}
		}
		else if(cur->GetVal() > processingNode){
			cur = cur->GetLeftChild();
			if(!cur){
				cur = new BinaryTreeNode<T>(processingNode);
				pre->left = cur;
			}
		}
		else
			return;
	}
}

template<class T> void BinarySearchTree<T>::DeleteNode(BinaryTreeNode<T> * processingNode){
	if(!processingNode)
		return;
	BinaryTreeNode<T> *tempPointer = nullptr;
	BinaryTreeNode<T> *tempParent = nullptr;
	BinaryTreeNode<T> *parent = this->Parent(processingNode);
	if(!processingNode->GetLeftChild())
		tempPointer = processingNode->GetRightChild();
	else{
		tempPointer = processingNode->GetLeftChild();
		while(tempPointer->GetRightChild()){
			tempParent = tempPointer;
			tempPointer = tempPointer->GetRightChild();
		}
		if(tempParent){
			tempParent->SetRightChild(tempPointer->GetLeftChild());
			tempPointer->SetLeftChild(processingNode->GetLeftChild());
		}
		else
			tempPointer->SetLeftChild(tempPointer->GetLeftChild());
		tempPointer->SetRightChild(processingNode->GetRightChild());
	}
	if(!parent)
		this->root = tempPointer;
	else
		if(parent->GetLeftChild() == processingNode)
			parent->SetLeftChild(tempPointer);
		else
			parent->SetRightChild(tempPointer);

	delete processingNode;
	processingNode = nullptr;
}

template<class T> BinaryTreeNode<T>* BinarySearchTree<T>::Parent(BinaryTreeNode<T> * childNode){
	if(!childNode)
		return nullptr;
	BinaryTreeNode<T> *cur = this->root;
	while(cur){
		if(cur->GetLeftChild() == childNode || cur->GetRightChild() == childNode)
			return cur;
		if(cur->GetVal() > childNode->GetVal())
			cur = cur->left;
		else
			cur = cur->right;
	}
	return nullptr;
}

template<class T> BinaryTreeNode<T>* BinarySearchTree<T>::Find(T& val){
	BinaryTreeNode<T> * res = nullptr;
	BinaryTreeNode<T> * cur = this->root;
	while(cur){
		if(cur->GetVal() == val){
			res = cur;
			break;
		}else if(cur->GetVal() > val)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return res;
}

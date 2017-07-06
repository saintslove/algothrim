/*
 * DoubleTree.cpp
 *
 *  Created on: 2016年11月29日
 *      Author: wangqi
 */

#include <iostream>
#include <queue>


template<typename T>
class TreeNode
{
public:
	TreeNode():left(NULL),right(NULL) {};

public:
	T Data;
	TreeNode<T>* left;
	TreeNode<T>* right;
};



template<typename T>
class BinaryTree
{
public:
	void PreOrder();
	void PreOrder(TreeNode<T>* CurrentNode);
	void PostOrder();
	void PostOrder(TreeNode<T>* CurrentNode);
	void InOrder();
	void InOrder(TreeNode<T>* CurrentNode);
	void LevelOrder();
	void showCurrentNode(TreeNode<T>* CurrentNode);


public:
	TreeNode<T>* Root;
};

template<typename T>
void BinaryTree<T>::showCurrentNode(TreeNode<T>* CurrentNode)
{
	std::cout<<CurrentNode->Data<<std::endl;
}

template<typename T>
void BinaryTree<T>::InOrder(TreeNode<T>* CurrentNode)
{
	if(CurrentNode){
		InOrder(CurrentNode->left);
		showCurrentNode(CurrentNode);
		InOrder(CurrentNode->right);
	}
}
template<typename T>
void BinaryTree<T>::PreOrder()
{
	InOrder(Root);
}


template<typename T>
void BinaryTree<T>::PreOrder(TreeNode<T>* CurrentNode)
{
	if(CurrentNode){
		showCurrentNode(CurrentNode);
		InOrder(CurrentNode->left);
		InOrder(CurrentNode->right);
	}
}
template<typename T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(Root);
}


template<typename T>
void BinaryTree<T>::PostOrder(TreeNode<T>* CurrentNode)
{
	if(CurrentNode){
		InOrder(CurrentNode->left);
		InOrder(CurrentNode->right);
		showCurrentNode(CurrentNode);
	}
}
template<typename T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(Root);
}


template<typename T>
void BinaryTree<T>::LevelOrder()
{
	std::queue<TreeNode<T>*> NodeQueue;
	TreeNode<T>* currentNode = Root;
	while(currentNode){
		showCurrentNode(currentNode);
		if(currentNode->left)
			NodeQueue.push(currentNode->left);
		if(currentNode->right)
			NodeQueue.push(currentNode->right);
		if(NodeQueue.empty()) return;
		currentNode = NodeQueue.front();
		NodeQueue.pop();
	}
}

































































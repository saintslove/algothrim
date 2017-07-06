/*
 * AVL.cpp
 *
 *  Created on: 2017年4月25日
 *      Author: lenovo
 */

/***************************************************************************************
 * 树结构参考链接   http://www.cnblogs.com/maybe2030/p/4732377.html
 ***************************************************************************************/
#include<iostream>
template <typename T>
class Node
{
private:
	T _data;
	int height;
	Node* left;
	Node* right;
public:
	Node(T data):_data(data),height(0),left(NULL),right(NULL) {}
};

/*
 * 右右旋转
 *
 * 	 		*
 * 	     *	   *
 * 		    *     *
 * 				    *
 */
template <typename T>
void SingRotateRight(Node<T>* node)
{
	Node<T> temp = node->right;
	node->right = temp->left;
	temp->left = node;
}

/*
 * 左左旋转
 *
 * 			*
 * 	     *	   *
 * 	  *     *
 * 	*
 *
 */
template <typename T>
void SingRotateLeft(Node<T>* node)
{
	Node<T> temp = node->left;
	node->left = temp->right;
	temp->right = node;
}


template <typename T>
void DoubleRotateLR(Node<T>* node)
{
	SingRotateRight(node->left);
	SingRotateLeft(node);
}

template <typename T>
void DoubleRotateRL(Node<T>* node)
{
	SingRotateLeft(node->right);
	SingRotateRight(node);
}































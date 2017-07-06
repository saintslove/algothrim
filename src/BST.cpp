/*
 * BST.cpp
 *
 *  Created on: 2016年11月29日
 *      Author: wangqi
 */


/***************************************************************************************
 * 树结构参考链接   http://www.cnblogs.com/maybe2030/p/4732377.html
 ***************************************************************************************/
#include <iostream>

template <typename T>
class BST;

template <typename T>
class Element
{
public:
	T key;
};

template <typename T>
class TreeNode
{
	friend class BST<T>;
private:
	TreeNode(Element<T>& x):Data(&x),left(NULL),right(NULL){};
	Element<T>* Data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	void display(int i);
};


template <typename T>
class BST
{
public:
	BST():Root(NULL) {};
	bool Insert(const Element<T>& data);
	TreeNode<T>& Serach(const Element<T>& data);
	TreeNode<T>& Serach(TreeNode<T>& node,const Element<T>& data);
	bool Delete(const Element<T>& data);
	bool DeleteAll(const Element<T>& data);
	TreeNode<T>& IterSerach(const Element<T>& data);

private:
	TreeNode<T>* Root;
};

template <typename T>
void TreeNode<T>::display(int i)
{
	std::cout<<"Position\t\t"<<i<<"\t\tData\t\t"<<Data->key<<"\n";
	if(left) left->display(2*i);
	if(right) right->display(2*i+1);
}

template <typename T>
bool BST<T>::Insert(const Element<T>& data)
{
	TreeNode<T>* current = Root;
	TreeNode<T>* father = 0; // father指向当前操作节点的父节点
	while(current)
	{
		father = current;
		if(current->Data->key == data.key)
			return false;
		if(current->Data->key > data.key)
			current = current->left;
		else if(current->Data->key < data.key)
			current = current->right;
	}

	current = new TreeNode<T>(data);
	if(!Root) Root = current;
	if(data.key < father->Data->key)
		father->left = current;
	else
		father->right = current;
}


template <typename T>
TreeNode<T>& BST<T>::Serach(const Element<T>& data)
{
	return Serach(Root,data);
}

template <typename T>
TreeNode<T>& BST<T>::Serach(TreeNode<T>& node,const Element<T>& data)
{
	if(!node)  return 0;
	if(node.Data->key == data.key)
		return node;
	else if(node.Data->key > data.key)
		return Serach(node.left,data);
	else
		return Serach(node.right,data);
}


template <typename T>
TreeNode<T>& BST<T>::IterSerach(const Element<T>& data)
{
	TreeNode<T>* current = Root;
	if(!current) return 0;
	while(current){
		if(data.key == current->Data->key)
			return current;
		else if(current->Data->key > data.key)
			current = current->left;
		else
			current = current->right;
	}
	return 0;
}




template <typename T>
bool BST<T>::Delete(const Element<T>& data)
{
	TreeNode<T>* current = Root;
	TreeNode<T>* parent = Root;
	bool isleft;
	while(current->Data->key != data.key){
		parent = current;
		if(current->Data->key < data.key && current->right != NULL){
			current = current->right;
			isleft = false;
		}
		else if(current->Data->key > data.key && current->left != NULL){
			current = current->left;
			isleft = true;
		}
		else
			return false;
	}
	/*
	 * @ current是叶子节点
	 */
	if(current->left == NULL && current->right == NULL){
		if(current == Root){
			delete Root;
			Root = NULL;
		}
		else if(isleft){
			delete current;
			parent->left = NULL;
		}
		else{
			delete current;
			parent->right = NULL;
		}
	}
	/*
	 * @ current只有右节点
	 */
	if(current->left == NULL && current->right != NULL){
		if(current == Root){
			Root = Root->right;
			delete current;
		}
		else if(isleft){
			parent->left = current->right;
			delete current;
		}
		else{
			parent->right = current->right;
			delete current;
		}
	}
	/*
	 * @ current只有左节点
	 */
	if(current->left != NULL && current->right == NULL){
		if(current == Root){
			Root = Root->left;
			delete current;
		}
		else if(isleft){
			parent->left = current->left;
			delete current;
		}
		else{
			parent->right = current->left;
			delete current;
		}
	}
	/*
	 * @ current有左右节点
	 */
	else{
		if(current == Root){
			DeleteAll(Root->Data);
		}
		TreeNode<T>* temp = current->right;
		TreeNode<T>* subParent = 0;
		while(temp->left != NULL){
			TreeNode<T>* subParent = temp;
			temp = temp->left;
		}
		if(isleft){
			parent->left = temp;
			subParent->left = temp->right;
			temp->left = current->left;
			temp->right = current->right;
			delete current;
		}
		else{
			parent->right = temp;
			subParent->left = temp->right;
			temp->left = current->left;
			temp->right = current->right;
			delete current;
		}
	}
}



template <typename T>
bool BST<T>::DeleteAll(const Element<T>& data)
{
	TreeNode<T>& Node = Serach(data);
	if(Node.left)
		DeleteAll(Node.left->Data);
	else if(Node.right)
		DeleteAll(Node.right->Data);
	delete Node;
	return false;
}































































/*
 * RedBlackTree.cpp
 *
 *  Created on: 2016年11月30日
 *      Author: wangqi
 */

#include <iostream>
#include <exception>
#include <iomanip>

template <typename T>
class RedBlackTree;

/*
 *  @节点
 */
template <typename T>
class TreeNode
{
private:
	enum Color
	{
		Red,
		Black,
	};

public:
	friend class RedBlackTree<T>;

private:
	TreeNode(T &data = T(),TreeNode<T>* lt = NULL,TreeNode<T>* rt = NULL,Color mColor = Black)
	:Data(data),left(lt),right(rt),color(mColor)
	{};
private:
	T Data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	Color color;
};

/*
 * @返回类型引用
 */
template <typename T>
class CRef
{
public:
	explicit CRef(const T & x):obj(&x) {}
	CRef():obj(NULL) {}
	inline bool IsNULL() {return obj == NULL;}
	inline T& get() const
	{
		if(IsNULL)
			throw std::exception("空指针");
		return *obj;
	}
private:
	const T* obj;
};


/*
 * @ 红黑树
 */
template <typename T>
class RedBlackTree
{
public:
	RedBlackTree(const T& negInfo);
	virtual ~RedBlackTree();
	void Insert(const T& data);
	void RotateWithLeftChild(TreeNode<T>* &Node)  const;
	void RotateWithRightChild(TreeNode<T>* &Node) const;
	void DoubleRotateWithLeftChild(TreeNode<T>* &Node) const;
	void DoubleRotateWithRightChild(TreeNode<T>* &Node) const;
	void HandleReorient(const T& item);
	TreeNode<T> *Rotate(const T& item,TreeNode<T> *GrandParentNode) const;
	bool IsEmpty();
	void MakeEmpty();
	void ReclaimMemory(TreeNode<T>* &Node);
	CRef<T> Find(const T& data);
	CRef<T> FindMax();
	CRef<T> FindMin();

private:
	TreeNode<T>* head;
	TreeNode<T>* nullNode;

	TreeNode<T>* current;  //当前节点
	TreeNode<T>* parent;	//父节点
	TreeNode<T>* grandfather;  //祖父节点
	TreeNode<T>* grandfatherfather;  //曾祖父节点
};

template <typename T>
CRef<T> RedBlackTree<T>::Find(const T& data)
{
	if(IsEmpty())
		return CRef<T>();
	TreeNode<T> * temp = head->right;
	if(data < temp->Data)
		Find(temp->left->Data);
	else if(data > temp->Data)
		Find(temp->right->Data);
	else if(temp != nullNode)
		return CRef<T>(temp->Data);
	else
		return CRef<T>();
}

template <typename T>
CRef<T> RedBlackTree<T>::FindMax()
{
	if(IsEmpty())
		return CRef<T>();
	TreeNode<T> * temp = head->right;
	while(temp->right != nullNode)
		temp = temp->left;
	return CRef<T>(temp->Data);
}


template <typename T>
CRef<T> RedBlackTree<T>::FindMin()
{
	if(IsEmpty())
		return CRef<T>();
	TreeNode<T> * temp = head->right;
	while(temp->left != nullNode)
		temp = temp->left;
	return CRef<T>(temp->Data);
}



template <typename T>
void RedBlackTree<T>::ReclaimMemory(TreeNode<T>* &Node)
{
	if(Node != Node->left){
		if(Node->left)
			ReclaimMemory(Node->left);
		if(Node->right)
			ReclaimMemory(Node->roght);
		delete Node;
	}
}


template <typename T>
void RedBlackTree<T>::MakeEmpty()
{
	ReclaimMemory(head->right);
	head->right = nullNode;
}


template <typename T>
bool RedBlackTree<T>::IsEmpty()
{
	return head->right == nullNode;
}



template <typename T>
RedBlackTree<T>::RedBlackTree(const T& negInfo)
:current(NULL)
,parent(NULL)
,grandfather(NULL)
,grandfatherfather(NULL)
{
	nullNode = new TreeNode<T>();
	nullNode->left = nullNode->right = nullNode;
	head = new TreeNode<T>(negInfo);
	head->left = head->right = nullNode;
}

template <typename T>
RedBlackTree<T>::~RedBlackTree()
{
	delete head;
	delete nullNode;
}


template <typename T>
void RedBlackTree<T>::Insert(const T& data)
{
	current = parent = grandfather = grandfatherfather = head;
	nullNode->Data = data;
	while(current->Data != data){
		/*
		 * 保留节点
		 */
		grandfatherfather = grandfather;
		grandfather = parent;
		parent = current;
		current = data < current->Data ? current->left : current->right;

		/*
		 * 左孩子与右孩子均为红色，需要调整，将外侧左孩子变为黑色，内测右孩子保持为红色
		 */
		if(current->left->color == TreeNode<T>::Color.Red && current->right->color == TreeNode<T>::Color.Red)
			HandleReorient(data);
	}
	/*
	 * 找到相同的节点
	 */
	if(current != nullNode)
		throw std::exception("can't insert same data");
	/*
	 * 未找到相同的节点，将其连接到父节点的字节点
	 */
	current = new TreeNode(data,nullNode,nullNode);
	if(current->Data < parent->Data)
		parent->left = current;
	else
		parent->right = current;

	HandleReorient(data);
}


/*
 *  @右转
 */
template <typename T>
void RedBlackTree<T>::RotateWithLeftChild(TreeNode<T>* &Node)  const
{
	TreeNode<T>* NodeLeft = Node->left;
	Node->left = NodeLeft->right;
	NodeLeft->right = Node;
	Node = NodeLeft;
}

/*
 *  @左转
 */
template <typename T>
void RedBlackTree<T>::RotateWithRightChild(TreeNode<T>* &Node) const
{
	TreeNode<T>* NodeRight = Node->right;
	Node->right = NodeRight->left;
	NodeRight->left = Node;
	Node = NodeRight;
}

template <typename T>
void RedBlackTree<T>::DoubleRotateWithLeftChild(TreeNode<T>* &Node) const
{
	RotateWithRightChild(Node->left);
	RotateWithLeftChild(Node);
}


template <typename T>
void RedBlackTree<T>::DoubleRotateWithRightChild(TreeNode<T>* &Node) const
{
	RotateWithLeftChild(Node->right);
	RotateWithRightChild(Node);
}


template <typename T>
void RedBlackTree<T>::HandleReorient(const T& item)
{
	current->color = TreeNode<T>::Color.Red;
	current->left->color = TreeNode<T>::Color.Black;
	current->right->color = TreeNode<T>::Color.Black;

	if(parent->color == TreeNode<T>::Color.Red){
		grandfather->color = TreeNode<T>::Color.Red;
		if(item < grandfather->Data != item < parent->Data)
			parent = Rotate(item,grandfather);
		current = Rotate(item,grandfatherfather);
		current->color = TreeNode<T>::Color.Black;
	}
	head->right->color = TreeNode<T>::Color.Black;
}

template <typename T>
TreeNode<T> *RedBlackTree<T>::Rotate(const T& item,TreeNode<T> *GrandParentNode) const
{
	if(item < GrandParentNode->Data){
		item < GrandParentNode->left->Data ?
				RotateWithLeftChild(GrandParentNode->left) :
				RotateWithRightChild(GrandParentNode->left);
		return GrandParentNode->left;
	}
	else{
		item < GrandParentNode->right->Data ?
				RotateWithLeftChild(GrandParentNode->right) :
				RotateWithRightChild(GrandParentNode->right);
		return GrandParentNode->right;
	}
}










































































































































































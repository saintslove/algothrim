/*
 * SequenStack.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: wangqi
 */
#include <algorithm>

/*
 * 顺序站
 */

template <typename T>
void ChangeSize(T* &list,int oldsize,int newsize)
{
	if(newsize < 0) throw "newsize < 0";
	T* temp = new T[newsize];
	int number = std::min(oldsize,newsize);
	std::copy(list,list+oldsize,temp);
	delete []list;
	list = temp;
}

template <typename T>
class ListQuene;

template <typename T>
class Node
{
	T* data;
	Node<T> *next;
public:
	Node(T element,Node<T>* next):data(element),next(next){}
	friend class ListQuene<T>;
};

template <typename T>
class ListQuene
{
	ListQuene();
	bool isEmpty() const;
	void Push(const T& item);
	void Pop();
	T& Front() const;
	T& Rear() const;
	~ListQuene();
private:
	Node<T>* front; //対首，空置，不保存数据
	Node<T>* rear;
};

template <typename T>
ListQuene<T>::ListQuene()
{
	front = rear = 0;
}

template <typename T>
ListQuene<T>::~ListQuene()
{
	while(!isEmpty())
	{
		Node<T>* temp = front->next;
		delete front;
		front = temp;
	}
}

template <typename T>
inline bool ListQuene<T>::isEmpty() const
{
	return front == 0;
}


template <typename T>
void  ListQuene<T>::Push(const T& item)
{
	if(isEmpty())
		front = rear = new Node<T>(item);
	else
		rear = rear->next = new Node<T>(item);
}

template <typename T>
inline void  ListQuene<T>::Pop()
{
	if(!isEmpty()){
		T& item = Front();
		Node<T> temp = front->next;
		delete front;
		front = temp;
		return item;
	}
	else
		throw "stack is empty";

}


template <typename T>
T& ListQuene<T>::Front() const
{
	if(isEmpty()) throw "quene empty";
	return front->data;
}

template <typename T>
T& ListQuene<T>::Rear() const
{
	if(isEmpty()) throw "quene empty";
	return rear->data;
}







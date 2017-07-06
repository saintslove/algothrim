/*
 * List.cpp
 *
 *  Created on: 2016年11月19日
 *      Author: wangqi
 */

#include <algorithm>

template <typename T,int N>
class List;

template <typename T,int N>
class ListIterator;

template <typename T,int N>
class Node
{
	friend class List<T,N>;
	friend class ListIterator<T,N>;
private:
	T data[N];
	Node<T,N>* next;
};

template <typename T,int N>
class List
{
private:
	Node<T,N>* first; //,链表头，指向第一个节点
	int capacity;
public:
	friend class ListIterator<T,N>;
	void List();
	void Insert(T& item,int position = 1);
	void  Delete(int position = 1);
	void  Delete(T Item);
	bool isEmpty();
	void Invert();
	void Concention(const List<T,N>& l);
};

template <typename T,int N>
void  List<T,N>::List():capacity(0)
{
	first = new Node<T,N>();
	first->data = 0;
	first->next = NULL;
}

template <typename T,int N>
void List<T,N>::Insert(T& item,int position)
{
	if(isEmpty())
	{
		Node<T,N>* node = new Node<T,N>();
		node->data = item;
		node->next = NULL;
		first->next = node;
	}
	if(position<=0 || position > capacity)  throw "Position error";
	Node<T,N>* privous = first;
	for(int i = 1;i < position;i++)
	{
		privous = privous->next;
	}
	capacity++;
	Node<T,N>* node = new Node<T,N>();
	node->data = item;
	node->next = privous->next;
	privous->next = node;
}

template <typename T,int N>
void List<T,N>::Delete(int position)
{
	if(isEmpty()) throw "empty list";
	if(position<=0 || position > capacity)  throw "Position error";
	Node<T,N>* privous = first;
	for(int i = 1;i < position;i++)
	{
		privous = privous->next;
	}
	if(position == capacity)
	{
		delete privous->next;
		privous->next = NULL;
	}
	else
	{
		Node<T,N>* Pos = privous->next;
		privous->next = Pos->next;
		Pos->next = NULL;
		delete Pos;
	}
	capacity--;
}

template <typename T,int N>
void List<T,N>::Delete(T Item)
{
	Node<T,N>* privous = first;
	for(;privous->next->data != Item && privous->next != NULL;)
	{
		privous = privous->next;
	}
	if(privous->next == NULL)
		std::cout<<"No Item"<<std::endl;
	else{
		Node<T,N>* Pos = privous->next;
		privous->next = Pos->next;
		Pos->next = NULL;
		delete Pos;
	}
}

template <typename T,int N>
bool List<T,N>::isEmpty()
{
	return capacity == 0;
}

template <typename T,int N>
void List<T,N>::Invert()
{
	Node<T,N>* p = first->next,*q = 0;
	while(p)
	{
		Node<T,N>* temp = q;
		q = p;
		p = p->next;
		q->next = temp;
	}
	first->next = q;
}

template <typename T,int N>
void List<T,N>::Concention(const List<T,N>& l)
{
	if(isEmpty()) { first->next = l.first->next; return;}
	if(!l.isEmpty())
	{
		Node<T,N>* privous = first;
		for(;privous->next != NULL;privous = privous->next);
		privous->next = l.first->next;
	}
}


template <typename T,int N>
class ListIterator
{
	const List<T,N> &list;
	Node<T,N>* current;
public:
	ListIterator(List<T,N> &l):list(l),current(l.first->next){};
	bool NotNull();
	bool NextNotNull();
	T* first();
	T* Next();
};

template <typename T,int N>
bool ListIterator<T,N>::NotNull()
{
	if(current) return true;
	else return false;
}

template <typename T,int N>
bool ListIterator<T,N>::NextNotNull()
{
	if(current && current->next) return true;
	else return false;
}

template <typename T,int N>
T* ListIterator<T,N>::first()
{
	Node<T,N>* temp = list.first->next;
	if(temp) return &temp->data;
	else return 0;
}

template <typename T,int N>
T* ListIterator<T,N>::Next()
{
	if(current && current->next)
		return &current->next->data;
	else return 0;

}




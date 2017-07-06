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
class SequeQuene
{
	SequeQuene(int Capacity = 10);
	bool isEmpty() const;
	void Push(const T& item);
	void Pop();
	T& Front() const;
	T& Rear() const;
	void ReSize();
	~SequeQuene();
private:
	T *quene;
	int front; //対首，空置，不保存数据
	int rear;
	int capacity;
};

template <typename T>
SequeQuene<T>::SequeQuene(int Capacity):capacity(Capacity)
{
	if(Capacity < 1) throw "Capacity < 0";
	quene = new T[Capacity];
	front = rear = 0;
}

template <typename T>
SequeQuene<T>::~SequeQuene()
{
	delete[] quene;
}

template <typename T>
inline bool SequeQuene<T>::isEmpty() const
{
	return front == rear;
}


template <typename T>
void  SequeQuene<T>::Push(const T& item)
{
	if((rear+1)%capacity == front)
		ReSize();
	rear = (rear+1)% capacity;
	quene[rear] = item;
}

template <typename T>
inline void  SequeQuene<T>::Pop()
{
	if(!isEmpty())
		quene[(front+1)%capacity].~T();
	else
		throw "stack is empty";

}

template <typename T>
void SequeQuene<T>::ReSize()
{
	T* temp = new T[2*capacity];
	int start = (front+1)%capacity;
	if(start < 2)    //no wrap
		std::copy(quene+start,quene+start+capacity-1,temp);
	else{
		std::copy(quene+start,quene+capacity,temp);
		std::copy(quene,quene+rear+1,temp+capacity-start);
	}
	front = 2*capacity-1;
	rear = capacity-2;
	capacity *= 2;
	delete []quene;
	quene = temp;
}

template <typename T>
T& SequeQuene<T>::Front() const
{
	if(isEmpty()) throw "quene empty";
	return quene[(front+1) % capacity];
}

template <typename T>
T& SequeQuene<T>::Rear() const
{
	if(isEmpty()) throw "quene empty";
	return quene[rear];
}







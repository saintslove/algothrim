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
class SequeStack
{
	SequeStack(int Capacity = 10);
	bool isEmpty() const;
	T& Top() const;
	void Push(const T& item);
	void Pop();
	void ReSize();
	~SequeStack();
private:
	T *stack;
	int top;
	int capacity;
};

template <typename T>
SequeStack<T>::SequeStack(int Capacity):capacity(Capacity)
{
	if(Capacity < 1) throw "Capacity < 0";
	stack = new T[Capacity];
	top = -1;
}

template <typename T>
SequeStack<T>::~SequeStack()
{
	delete[] stack;
}

template <typename T>
inline bool SequeStack<T>::isEmpty() const
{
	return top == -1;
}

template <typename T>
T& SequeStack<T>::Top() const
{
	if(!isEmpty())
		return stack[top];
	else
		throw "stack is empty";
}

template <typename T>
void  SequeStack<T>::Push(const T& item)
{
	if(top == capacity-1){
		ChangeSize(stack,capacity,2*capacity);
		capacity *= 2;
	}
	stack[++top] = item;
}

template <typename T>
inline void  SequeStack<T>::Pop()
{
	if(!isEmpty())
		stack[top--].~T();
	else
		throw "stack is empty";

}

template <typename T>
void SequeStack<T>::ReSize()
{
	T* temp = new T[2*capacity];
	std::copy(stack,stack+capacity,temp);
	capacity *= 2;
	top = stack+capacity-1;
	delete []stack;
	stack = temp;
}









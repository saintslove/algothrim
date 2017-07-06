/*
 * HeapSort.cpp
 *
 *  Created on: 2016年12月2日
 *      Author: wangqi
 */

#include <iostream>
#include <exception>
#include <cassert>
/*
 * @大顶堆
 */
template <typename T>
class Heap
{
	Heap(int size = 100);
	virtual ~Heap();
	bool IsEmpty();
	void Push(const T& data);
	void Pop();
	const T& Top() const;
	void Resize(int N);

private:
	/*
	 * 表明堆时固定大小的
	 */
	T* HeapArray;
	int MaxSize;
	int CurrentSize;

private:
	void TrickleUp(int index);
	void TrickleDown(int index);
};


template <typename T>
Heap<T>::Heap(int size)
: MaxSize(size)
 ,CurrentSize(0)
 ,HeapArray(NULL)
{
	if(size < 1)
		throw std::logic_error("数组参数非法");
	HeapArray = new T[MaxSize];
}


template <typename T>
void Heap<T>::Resize(int N)
{
	assert(N > 1);
	MaxSize *= N;
	T* NewHeapArray = new T[MaxSize];
	delete[] HeapArray;
	HeapArray = NewHeapArray;
}



template <typename T>
virtual Heap<T>::~Heap()
{
	delete[] HeapArray;
	HeapArray = NULL;
}

template <typename T>
bool Heap<T>::IsEmpty()
{
	return CurrentSize == 0;
}

template <typename T>
void Heap<T>::Push(const T& data)
{
	if(CurrentSize >= MaxSize)
		Resize(2);
	HeapArray[CurrentSize] = data;
	TrickleUp(CurrentSize++);
}


template <typename T>
void Heap<T>::TrickleUp(int index)
{
	int Parent = (index-1) / 2;
	T temp = HeapArray[index];

	while(Parent > 0 && HeapArray[Parent] < temp)
	{
		HeapArray[index] = HeapArray[Parent];
		index = Parent;
		Parent = (index - 1) / 2;
	}
	HeapArray[index] = temp;
}


template <typename T>
void Heap<T>::TrickleDown(int index)
{

	int temp = HeapArray[index];
	int largeIndex;
	while(index < CurrentSize/2)
	{
		int Left = index*2+1;
		int Right = Left+1;
		if(Right < CurrentSize && HeapArray[Left] < HeapArray[Right] )
			largeIndex = Right;
		else
			largeIndex = Left;
		if(temp >= HeapArray[largeIndex])
			break;
		HeapArray[index] = HeapArray[largeIndex];
		index = largeIndex;
	}
	HeapArray[index] = temp;
}

template <typename T>
void Heap<T>::Pop()
{
	if(IsEmpty())
		throw std::logic_error("空堆");
	HeapArray[0] = HeapArray[--CurrentSize];
	TrickleDown(0);
}


template <typename T>
const T& Heap<T>::Top() const
{
	return HeapArray[0];
}














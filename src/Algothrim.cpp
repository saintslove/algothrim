//============================================================================
// Name        : Algothrim.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;




int main() {
	int data[]={23, 65, 12, 3, 8, 76, 345, 90, 21, 75,3,5896,1253,58,91,27,6,68894985};    //输入待排序数组
	//BubbleSort(data,8);              //冒泡排序法
	radixSort(data,18,11);
	for(int i=0;i<18;i++)
	   cout<<data[i]<<" ";
	return 0;
}


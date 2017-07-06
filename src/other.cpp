/*
 * other.cpp
 *
 *  Created on: 2017年4月25日
 *      Author: lenovo
 */

/*
 * 柔性数组
 * 1.柔性数组成员前面必须至少一个其他成员 ,比如a,b
 * 2.柔性数组成员允许结构中包含一个大小可变的数组 比如c
 * 3.柔性数组成员只作为一个符号地址存在，而且必须是结构体的最后一个成员，sizeof 返回的这种结构大小不包括柔性数组的内存
 */


struct test
{
	int a;
	double b;
	char c[];
	//char c[0];
};

test* pTest = (test*)new char[sizeof(test)+100*sizeof(char)];



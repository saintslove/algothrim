/*
 * Sort.cpp
 *
 *  Created on: 2017年3月27日
 *      Author: lenovo
 */

/*
 * 冒泡排序
 * 最差时间 O(n*n)
 * 平均时间复杂度O(n*n)
 * 空间复杂度O(1)
 * 稳定度:稳定
 * 冒泡排序的基本原理是：依次比较相邻的两个数，将大数放在前面，小数放在后面。
 */
void BubbleSort(int* pData,int count)
{
	for(int i = 0;i < count-1;i++)
	{
		for(int j = i+1;j < count;j++)
		{
			if(pData[i] < pData[j])
			{
				int temp = pData[i];
				pData[i] = pData[j];
				pData[j] = temp;
			}
		}
	}
}

void BulleSort(int* pData, int Count)
{
    int iTemp=0;
    for(int i=1;i<Count;i++)     //进行Count次排序，Count是排序的数的个数
    {
        for(int j=Count-1;j>=i;j--)  //对该轮待排序的数进行排序
        {
            if(pData[j]<pData[j-1])  //将大数放在前，小数放在后
            {
                iTemp=pData[j-1];
                pData[j-1]=pData[j];
                pData[j]=iTemp;
            }
        }
    }
}

/*
 * 鸡尾酒排序/双向冒泡法
 * 时间复杂度O(n*n)
 * 升序排序
 * 基本原理:对要排序的数组进行双向冒泡排序
 */

void CockTail(int* pData,int count)
{
	int tail = count-1;
	for(int i = 0; i < tail;)
	{
		for(int j = tail;j > i;j--)
		{
			if(pData[j] < pData[j-1])
			{
				int temp = pData[j];
				pData[j] = pData[j-1];
				pData[j-1] = temp;
			}
		}
		++i;
		for(int m = i;m < tail;m++)
		{
			if(pData[m] > pData[m+1])
			{
				int temp = pData[m];
				pData[m] = pData[m+1];
				pData[m+1] = temp;
			}
		}
		--tail;
	}
}

/*
 * 选择排序
 * 时间复杂度O(n*n)
 * 空间复杂度O(1)
 * 稳定
 * 基本思想是：从需要排序的数据中选择最小的同第一个值交换，再从剩下的部分中选择最小的与第二个交换，循环下去，最后实现全队列的排序。
 */
void selectSort(int* pData,int count)
{
	for(int i = 0; i < count-1;i++)
	{
		int pos = i;
		for(int j = i+1;j < count;j++)
		{
			if(pData[j] < pData[i])
				pos = j;
		}
		int temp = pData[pos];
		pData[pos] = pData[i];
		pData[i] = temp;
	}
}

/*
 * 直接插入排序
 * 时间复杂度：O(n*n)-O(n) 平均O(n)
 * 空间复杂度：O(1)
 * 稳定性：稳定
 * 原理：1）从第一个元素开始，该元素可以认为已经被排序
	2）取出下一个元素，在已经排序的元素序列中从后向前扫描
	3）如果该元素（已排序）大于新元素，将该元素移到下一位置
	4）重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
	5）将新元素插入到该位置后
	6）重复步骤2~5
 */
void insertSort(int* pData,int count)
{
	int temp,pos;
	for(int i = 1;i < count;i++)
	{
		temp = pData[i];
		pos = i-1;
		while(pos >= 0 && pData[pos] > temp)
		{
			pData[pos+1] = pData[pos];
			pos--;
		}
		pData[pos+1] = temp;
	}
}

/*
 * 归并算法
 * 时间复杂度：O(NlogN)
 * 空间复杂度:O(n+logN)
 * 稳定
 * 基本思想：采用分治法先将待排序的序列分为两部分，再对这两部分分别进行排序，这两部分排序之后再将其进行合并
 */
void Merge(int* pData,unsigned int first,unsigned int mid,unsigned int last)
{
	unsigned int begin1 = first,end1 = mid,begin2 = mid+1,end2 = last;
	int* temp = new int[last-first+1];
	unsigned int k = 0;
	while((begin1 <= end1)&&(begin2 <= end2))
	{
		if(pData[begin1] <= pData[begin2])
			temp[k++] = pData[begin1++];
		else
			temp[k++] = pData[begin2++];
	}
	while(begin1 <= end1)
	{
		temp[k++] = pData[begin1++];
	}
	while(begin2 <= end2)
	{
		temp[k++] = pData[begin2++];
	}
	for(unsigned int i = 0;i < k;i++)
		pData[first+i] = temp[i];
	delete[] temp;
}

void MergeSort(int* pData,unsigned int first,unsigned int last)
{
	if(first < last)
	{
		int mid = (first + last)/2;
		MergeSort(pData,first,mid);
		MergeSort(pData,mid+1,last);
		Merge(pData,first,mid,last);
	}
}

/*
 * 快速排序
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(logN)-O(n)
 * 不稳定
 * 快速排序的基本思想:先选择中间值，然后把比它小的放在左边，大的放在右边（具体的实现就是从两边找，找到一对后交换），然后对两边分别通过递归调用快速排序，最后两种子序列是已经排序好的，直接合并就可以了。
 */

void swap(int* pData,int i,int j)
{
	int temp = pData[i];
	pData[i] = pData[j];
	pData[j] = temp;
}
void quickSort(int* pData,int left,int right)
{
	if(left >= right)
		return;
	swap(pData,left,(left+right)/2);
	int last = left;
	for(int i = left+1;i <= right;i++)
	{
		if(pData[i] < pData[left])
			swap(pData,++last,i);
	}
	swap(pData,left,last);
	quickSort(pData,left,last-1);
	quickSort(pData,last+1,right);
}

/*
 * 希尔排序
 * 时间复杂度：其复杂度依赖于其Gap序列，范围Ο(n^1.5) ~ Ο(n^2)。而最好的情况则是序列初始状态就是顺序排列，此时算法的复杂度是O(n)。平均复杂度则为：Ο(n^5/4)
 * 空间复杂度：O(1)
 * 稳定性：不稳定
 * 原理：1）假设序列的元素个数是n，选取一个初始Gap的d（d<n）；
	   2）将序列中元素之间距离（即Gap）为d的元素分为一组，在每组之间直接进行插入排序；
	   3）全部完成以后，缩小Gap至d1（d1<d），然后继续2）直到Gap为1；
 */
void ShellSort(int* pData,int count)
{
	int temp = 0;
	for (int gap = count / 2; gap >= 1; gap = gap / 2)
		for (int i = gap; i < count; i++)
			for (int j = i; j >= gap && pData[j] < pData[j - gap]; j -= gap)
			{
				temp = pData[j];
				pData[j] = pData[j - gap];
				pData[j - gap] = temp;
			}
}

/*
 * 堆排序
 * 时间复杂度：O（n*log2（n））
 * 空间复杂度：O(1)
 * 稳定性：不稳定
 * 原理：堆排序主要用来处理大批量的数据排序，堆排序使用了大根堆（或小根堆）堆顶记录的关键字最大（或最小）这一特征，建立堆来进行排序，使得在当前无序区中选取最大（或最小）关键字的记录变得简单。
 */

/*
 * 基数排序，最低有效关键字开始排序称为 LSD，最高有效关键字开始排序称为 MSD
 * 时间复杂度：
 * 空间复杂度：O(N)
 * 稳定性：稳定
 * 原理：第一次排序(个位):
		3 4 2
		5 7 6
		3 5 6
		0 5 8
		第二次排序(十位):
		3 4 2
		3 5 6
		0 5 8
		5 7 6
		第三次排序(百位):
		0 5 8
		3 4 2
		3 5 6
		5 7 6
		结果: 58 342 356 576

		m代表最大数的位数
*/

int power(int m)
{
	int ret = 1;
	for(int i = 0;i < m-1;i++)
		ret *= 10;
	return ret;
}
void radixSort(int* pData,int count,int m)
{
	int temp[10][count];
	int order[10] = {0};
	int n = 1;
	while(n <= power(m) )
	{
		for(int i = 0;i < count;i++)
		{
			int lsd = (pData[i]/n)%10;
			temp[lsd][order[lsd]] = pData[i];
			order[lsd]++;
		}
		int pos = 0;
		for(int i = 0;i < 10;i++)
		{
			if(order[i] > 0)
			{
				for(int j = 0;j < order[i];j++)
					pData[pos++] = temp[i][j];
			}
			order[i] = 0;
		}
		n *= 10;
	}
}


/*
 * 桶排序
 * 稳定
 *
 */

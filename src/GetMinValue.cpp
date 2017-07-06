///*
// * GetMinValue.cpp
// *
// *  Created on: 2017年3月6日
// *      Author: lenovo
// */
//
//
//
//#include<mutex>
///**
// * 获得最小值的栈
// * 时间复杂度O(1)
// * 空间复杂度O(n)
// */
//
//#include <stack>
//#include <deque>
//#include <ext/hash_map>
//#include <ext/hash_set>
//#include <exception>
//#include <algorithm>
//
//
//class MyStack1
//{
//private:
//	 std::stack<int> stackData;
//	 std::stack<int> stackMin;
//
//public:
//	 MyStack1();
//	 void push(int data);
//	 int pop();
//	 int getmin();
//	 virtual ~MyStack1();
//};
//
//
//MyStack1::MyStack1()
//{
//	stackData = new std::stack<int>();
//	stackMin = new std::stack<int>();
//}
//
//MyStack1::~MyStack1()
//{
//	delete stackData;
//	delete stackMin;
//}
//
//void MyStack1::push(int data)
//{
//	stackData.push(data);
//	if(stackMin.empty())
//		stackMin.push(data);
//	else if(data <= stackMin.top())
//		stackMin.push(data);
//	stackData.push(data);
//}
//
//int MyStack1::pop()
//{
//	if(stackData.empty())
//		throw new std::runtime_error("Empty Stack");
//	int value = stackData.top();
//	if(value == getmin())
//		stackMin.top();
//	return value;
//}
//
//int MyStack1::getmin()
//{
//	if(stackMin.empty())
//		throw new std::runtime_error("Empty Stack");
//	return stackMin.top();
//}
//
//
//
///*
// * 由两个栈组成队列
// */
//
//class Stackqueue
//{
//private:
//	std::stack<int> stackPush;
//	std::stack<int> stackPop;
//
//public:
//	Stackqueue();
//	virtual ~Stackqueue();
//	void push(int data);
//	int pop();
//	int peek();
//};
//
//
//Stackqueue::Stackqueue()
//{
//	stackPush = new std::stack<int>();
//	stackPop = new std::stack<int>();
//}
//Stackqueue::~Stackqueue()
//{
//	delete stackPush;
//	delete stackPop;
//}
//
//void Stackqueue::push(int data)
//{
//	stackPush.push(data);
//}
//
//int Stackqueue::pop()
//{
//	if(stackPop.empty() && stackPush.empty())
//		throw std::runtime_error("Empty Queue");
//	if(stackPop.empty())
//	{
//		while(!stackPush.empty())
//		{
//			stackPop.push(stackPush.top());
//			stackPush.pop();
//		}
//	}
//	return stackPop.pop();
//}
//
//int Stackqueue::peek()
//{
//	return stackPop.top();
//}
//
///*
// * 使用递归函数实现栈反转
// */
//
//int getlastandremove(std::stack<int> Stack)
//{
//	int value = Stack.top();
//	Stack.pop();
//	if(Stack.empty())
//		return value;
//	else{
//		int last = getlastandremove(Stack);
//		Stack.push(value);
//		return last;
//	}
//}
//
//void reverse(std::stack<int> Stack)
//{
//	if(Stack.empty())
//		return;
//	int value = getlastandremove(Stack);
//	reverse(Stack);
//	Stack.push(value);
//}
//
//
///*
// * 用一个栈实现另一个栈的排序
// */
//void sortStackByStack(std::stack<int> Stack)
//{
//	std::stack<int> help = new std::stack<int>();
//	while(!Stack.empty())
//	{
//		int value = Stack.top();
//		Stack.pop();
//		while(!help.empty() && value > help.top())
//		{
//			Stack.push(help.top());
//			help.pop();
//		}
//		help.push(value);
//	}
//	while(!help.empty())
//	{
//		Stack.push(help.top());
//		help.pop();
//	}
//
//}
//
//
///*
// * 栈实现汉诺塔问题
// */
//
///*
// * 猫狗问题
// */
//
//
///*
// * 生成窗口最大值数组
// * 时间复杂度O(N)
// */
//
//class tag
//{
//private:
//	int m_len;
//	int arr[m_len];
//public:
//	tag(int len):m_len(len){};
//};
//
//int* getMaxWindow(const int* arr,int arrlen,int len)
//{
//	tag Tag(arrlen - len +1);
//	int index = 0;
//	if(arr ==  NULL || len <= 0 || arrlen < len)
//		return NULL;
//	std::deque<int> qmax = new std::deque<int>();
//	for(int i = 0;i < arrlen;i++)
//	{
//		while(!qmax.empty() && arr[*qmax.rbegin()] <= arr[i])
//		{
//			qmax.pop_back();
//		}
//		qmax.push_back(i);
//		if(*qmax.begin() == i - len)
//			qmax.pop_front();
//	}
//	Tag.arr[index++] = arr[*qmax.begin()];
//	qmax.pop_front();
//	return Tag.arr;
//}
//
//
///*
// * 构造数组的最大树 MaxTree
// * 时间复杂度O(N)
// * 空间复杂度O(N)
// */
//
//class Node
//{
//private:
//	int value;
//	Node left;
//	Node right;
//public:
//	Node(int Data):value(Data),left(NULL),right(NULL){};
//};
//
//using namespace __gnu_cxx;
//
//void popStacksetMap(std::stack<Node> Stack,hash_map<Node,Node> map)
//{
//	Node node = Stack.top();
//	Stack.pop();
//	if(!Stack.empty())
//		map.insert(std::pair<Node,Node>(node,NULL));
//	else
//		map.insert(std::pair<Node,Node>(node,Stack.top()));
//}
//
//Node getMaxTree(const int* arr,int len)
//{
//	Node* nArr = new Node[len];
//	std::stack<Node> Stack = new std::stack<Node>();
//	hash_map<Node,Node> lBigMap = new hash_map<Node,Node>();
//	hash_map<Node,Node> rBigMap = new hash_map<Node,Node>();
//	for(int i = 0;i < len;i++)
//	{
//		nArr[i] = new Node(arr[i]);
//	}
//	for(int i = 0;i < len;i++)
//	{
//		Node curNode = nArr[i];
//		while(!Stack.empty() && Stack.top().value < curNode.value)
//			popStacksetMap(Stack,lBigMap);
//		Stack.push(curNode);
//	}
//	while(!Stack.empty())
//		popStacksetMap(Stack,lBigMap);
//	for(int i = len -1;i>=0;i--)
//	{
//		Node curNode = nArr[i];
//		while(!Stack.empty() && Stack.top().value < curNode.value)
//			popStacksetMap(Stack,rBigMap);
//		Stack.push(curNode);
//	}
//	while(!Stack.empty())
//		popStacksetMap(Stack,lBigMap);
//	Node head = NULL;
//	for(int i = 0;i < len;i++)
//	{
//		Node curNode = nArr[i];
//		Node left = lBigMap(curNode);
//		Node right = rBigMap(curNode);
//		if(left == NULL && right == NULL){
//			head = curNode;
//		}
//		else if(left == NULL){
//			if(right.left == NULL)
//				right.left = curNode;
//			else
//				right.right = curNode;
//		}
//		else if(right == NULL){
//			if(left.left == NULL)
//				left.left = curNode;
//			else
//				left.right = curNode;
//		}
//		else{
//			Node parent = left.value < right.value ? left : right;
//			if(parent.left == NULL)
//				parent.left = curNode;
//			else
//				parent.right = curNode;
//		}
//	}
//	return head;
//}
//
//
///*
// * 求最大子矩阵的大小
// * 时间复杂度O(N*M)
// */
//
///*
// * 最大数减去最小数小于等于 num 的子数组数量
// */
//
//
//int GetNum(int* arr,int arrlen,int num)
//{
//	int ret = 0;
//	if(arr == NULL || arrlen == 0)
//		return 0;
//	std::deque<int> qmax = std::deque<int>();
//	std::deque<int> qmin = std::deque<int>();
//	int i = 0,j = 0;
//	while(i++ < arrlen){
//		while(j++ < arrlen){
//			while(!qmax.empty() && arr[*qmax.rbegin()] <= arr[j])
//				qmax.pop_back();
//			qmax.push_back(j);
//			while(!qmin.empty() && arr[*qmin.rbegin()] >= arr[j])
//				qmin.pop_back();
//			qmin.push_back(j);
//			if(*qmax.begin() - *qmin.end() > num)
//				break;
//		}
//		if(*qmax.begin() == i)
//			qmax.pop_front();
//		if(*qmin.begin() == i)
//			qmin.pop_front();
//		ret += j - i;
//	}
//	return ret;
//}
//
///*
// * 打印两个有序链表公共部分
// */
//
//class Nodes
//{
//private:
//	int value;
//	Nodes next;
//public:
//	Nodes(int Data):value(Data),next(NULL){};
//};
//
//void printCommonPart(Nodes head1,Nodes head2)
//{
//	while(head1 != NULL && head2 != NULL)
//	{
//		if(head1.value < head2.value)
//			head1 = head1.next;
//		if(head1.value > head2.value)
//			head2 = head2.next;
//		else{
//			std::cout<<head1.value<<std::endl;
//			head1 = head1.next;
//			head2 = head2.next;
//		}
//	}
//}
//
///*
// * 在单链表和双链表中删除倒数第K个节点
// * 时间复杂度O(N)
// * 空间复杂度O(N)
// */
//Nodes DeleteKNode(Nodes head,int K)
//{
//	if(head == NULL || K < 1)
//		return head;
//	Nodes curNode = head;
//	while(curNode != NULL){
//		curNode = curNode.next;
//		K--;
//	}
//	if(K == 0)
//		head = head.next;
//	if(K < 0){
//		curNode = head;
//		while(++K != 0)
//			curNode = curNode.next;
//		curNode.next = curNode.next.next;
//	}
//	return head;
//}
//
//Node DeleteKNode(Node head,int K)
//{
//	if(head == NULL || K < 1)
//		return head;
//	Node curNode = head;
//	while(curNode != NULL){
//		curNode = curNode.right;
//		K--;
//	}
//	if(K == 0){
//		head = head.right;
//		head.left = NULL;
//	}
//	if(K < 0){
//		curNode = head;
//		while(++K != 0)
//			curNode = curNode.right;
//		curNode.right = curNode.right.right;
//		if(curNode.right.right != NULL)
//			curNode.right.right.left = curNode;
//	}
//		return head;
//}
//
//
///*
// * 删除链表的中间节点和a/b出的节点
// */
//Nodes DeleteMidNode(Nodes head)
//{
//	if(head == NULL || head.next == NULL)
//		return head;
//	if(head.next.next == NULL)
//		return head.next;
//	Nodes pre = head;
//	Nodes cur = head.next.next;
//	while(cur.next != NULL && cur.next.next != NULL){
//		pre = pre.next;
//		cur = cur.next.next;
//	}
//	pre.next = pre.next.next;
//	return head;
//}
//
//Nodes DeleteByRatio(Nodes head,int a,int b)
//{
//	if(a < 1 || a > b)
//		return head;
//	Nodes cur = head;
//	int n = 0;
//	while(cur != NULL){
//		n++;
//		cur = cur.next;
//	}
//	n = (int)((double)(a*n) / (double)b);
//	if(n ==1)
//		head = head.next;
//	else{
//		cur = head;
//		while(--n != 1)
//			cur = cur.next;
//		cur.next = cur.next.next;
//	}
//		return head;
//}
//
///*
// * 反转单向与双向链表
// */
//Nodes reverseList(Nodes head)
//{
//	Nodes pre = NULL;
//	Nodes next = NULL;
//	while(head != NULL){
//		next = head.next;
//		head.next = pre;
//		pre = head;
//		head = next;
//	}
//	return pre;
//}
///*
// * 思路：每次都将原第一个结点之后的那个结点放在新的表头后面。
//比如1,2,3,4,5
//第一次：把第一个结点1后边的结点2放到新表头后面，变成2,1,3,4,5
//第二次：把第一个结点1后边的结点3放到新表头后面，变成3,2,1,4,5
//……
//直到： 第一个结点1，后边没有结点为止。
// */
//Nodes* ReverseList(Nodes* pHead)
//{
//	if(pHead == NULL)
//		return pHead;
//
//	Nodes *res,*first,*temp;
//	res = new Nodes(-1);
//	res->next = pHead;
//
//	first = res->next;       //first 始终为第一个结点，不断后移
//	while(first->next!=NULL) //temp为待前差的
//		{
//		temp = first->next;
//		first->next = temp->next;
//		temp->next = res->next;
//		res->next = temp;
//	}
//
//	return res->next;
//}
//
//Node reverseList(Node head)
//{
//	Node pre = NULL;
//	Node next = NULL;
//	while(head != NULL){
//		next = head.right;
//		head.right = pre;
//		head.left = next;
//		pre = head;
//		head = next;
//	}
//	return pre;
//}
//
//
///*
// * 反转部分单向链表
// */
//Nodes reversePartList(Nodes head,int from,int to)
//{
//	int len = 0;
//	Nodes fPre = NULL;
//	Nodes fPos = NULL;
//	Nodes node1 = head;
//	while(node1 != NULL){
//		len++;
//		fPre = len == from -1 ? node1 : fPre;
//		fPos = len == to + 1 ? node1 : fPos;
//		node1 = node1.next;
//	}
//	if(from > to || from < 1 || to > len)
//		return head;
//	node1 = fPos == NULL ? head : fPre.next;
//	Nodes node2 = node1.next;
//	node1.next == fPos;
//	Nodes next = NULL;
//	while(node2 != fPos){
//		next = node2.next;
//		node2.next = node1;
//		node1 = node2;
//		node2 = next;
//	}
//	if(fPre != NULL){
//		fPre.next = node1;
//		return head;
//	}
//	return node1;
//}
//
///*
// * 判断链表是否为回文
// */
//bool isPalindrome2(Nodes head)
//{
//	if(head == NULL || head.next == NULL)
//		return true;
//	Nodes right = head.next;
//	Nodes cur = head;
//	while(cur.next != NULL && cur.next.next != NULL){
//		right = right.next;
//		cur = cur.next.next;
//	}
//	std::stack<Nodes> Stack = new std::stack<Node>();
//	while(right != NULL){
//		Stack.push(right);
//		right = right.next;
//	}
//	while(!Stack.empty()){
//		if(head.value != Stack.top().value){
//			return false;
//		}
//		Stack.pop();
//		head = head.next;
//	}
//	return head;
//}
//
//bool isPalindrome3(Nodes head)
//{
//	if(head == NULL || head.next == NULL)
//		return true;
//	Nodes node1 = head;
//	Nodes node2 = head;
//	while(node1 != NULL && node1.next.next != NULL){
//		node1 = node1.next;
//		node2 = node2.next.next;
//	}
//	node2 = node1.next;
//	node1.next = NULL;
//	Nodes node3 = node2.next;
//	while(node2 != NULL){
//		node3 = node2.next;
//		node2.next = node1;
//		node1 = node2;
//		node2 = node3;
//	}
//	bool ret = true;
//	node3 = node1;
//	node2 = head;
//	while(node2 != NULL || node1 != NULL){
//		if(node2.value != node1.value)
//			ret = false;
//		node2 = node2.next;
//		node1 = node1.next;
//	}
//	node1 = node3.next;
//	while(node1 != NULL){
//		node2 = node1.next;
//		node1.next = node3;
//		node3 = node1;
//		node1 = node2;
//	}
//	return ret;
//}
//
//
///*
// * 删除无序链表中重复出现的点
// * 时间复杂度O(N)
// * 空间复杂度O(N)
// */
//
//void removeRep1(Nodes head)
//{
//	if(head == NULL || head.next == NULL)
//		return;
//	hash_set<int> set = new hash_set<int>();
//	set.insert(head.value);
//	Nodes pre = head;
//	Nodes cur = head.next;
//	while(cur != NULL){
//		if(set.find(cur.value) != NULL)
//			pre.next == cur.next;
//		else{
//			set.insert(cur.value);
//			pre = cur;
//		}
//		cur = cur.next;
//	}
//}
//
//
///*
// * 在单链表种删除指定值的节点
// * 时间复杂度O(N)
// * 空间复杂度O(1)
// */
//Node removeValue(Nodes head,int num)
//{
//	if(head == NULL)
//		return head;
//	while(head != NULL){
//		if(head.value != num)
//			break;
//		head = head.next;
//	}
//	Nodes pre = head;
//	Nodes cur = head.next;
//	while(cur != NULL){
//		if(cur.value == num)
//			pre.next = cur.next;
//		else{
//			pre.next = cur;
//			pre = cur;
//		}
//		cur = cur.next;
//	}
//	return pre;
//}
//
///*
// * 将搜索二叉树转换为双向链表
// */
//
///*
// * 时间复杂度O(N)
// * 空间复杂度O(N)
// */
//void inOrderToQueue(Node head,std::deque<Node> queue)
//{
//	if(head == NULL)
//		return;
//	inOrderToQueue(head.left,queue);
//	queue.push_back(head);
//	inOrderToQueue(head.right,queue);
//}
//
//
//Node covert1(Node head)
//{
//	std::deque<Node> queue = new std::deque<Node>();
//	inOrderToQueue(head,queue);
//	if(queue.empty())
//		return head;
//	head = *queue.begin();
//	queue.pop_front();
//	Node pre = head;
//	Node cur = NULL;
//	while(!queue.empty()){
//		cur = *queue.begin();
//		pre.right = cur;
//		cur.left = pre;
//		pre = cur;
//		queue.pop_front();
//	}
//	pre.right = NULL;
//	return head;
//}
//
//
///*
// * 使用递归实现树的转换
// * 时间复杂度O(N)
// * 空间复杂度O(h),h为树高
// */
//
//Node process(Node head)
//{
//	if(head == NULL)
//		return head;
//	Node leftE = process(head.left);
//	Node rightE = process(head.right);
//	Node leftS = leftE != NULL ? leftE.right : NULL;
//	Node rightS = rightE != NULL ? rightE.right : NULL;
//	if(leftE != NULL || rightE != NULL){
//		leftE.right = head;
//		head.left = leftE;
//		head.right = rightS;
//		rightS.left = head;
//		rightE.right = leftS;
//		return rightE;
//	}
//	else if(leftE != NULL){
//		leftE.right = head;
//		head.left = leftE;
//		head.right = leftE;
//		return head;
//	}
//	else if(rightE != NULL){
//		head.right = rightS;
//		rightS.left = head;
//		rightE.right = head;
//		return rightE;
//	}
//	else{
//		head.right = head;
//		return head;
//	}
//}
//
//Node covert2(Node head)
//{
//	if(head == NULL)
//		return head;
//	Node last = process(head);
//	head = last.right;
//	last.right = NULL;
//	return head;
//}
//
//
///*
// * 单链表的选择排序
// * 空间复杂度O(1)
// */
//
//Node getPre(Node head)
//{
//	Node smallPre = NULL;
//	Node small = head;
//	Node pre = head;
//	Node cur = head.right;
//	while(cur != NULL){
//		if(small.value > cur.value){
//			smallPre = pre;
//			small = cur;
//		}
//		pre = cur;
//		cur = cur.right;
//	}
//	return smallPre;
//}
//
//Node selectSort(Node head)
//{
//	Node tail = NULL; //排序部分尾部
//	Node cur = head;  //未排序部分头部
//	Node pre = NULL; //最小节点前一个节点
//	Node small = NULL; //最小节点
//	while(cur != NULL){
//		small = cur;
//		pre = getPre(cur);
//		if(pre != NULL){
//			small = pre.right;
//			pre.right = small.right;
//		}
//		cur = cur == small ? cur.right : cur;
//		if(tail == NULL)
//			head = small;
//		else
//			tail.right = small;
//		tail = small;
//	}
//	return head;
//}
//
///*
// * 一种怪异的节点删除
// * 只知道链表的某一节点，链表头不知，删除该节点
// * 时间复杂度O(1)
// */
//void removeNode(Node node)
//{
//	if(node == NULL)
//		return;
//	Node next = node.right;
//	if(next == NULL)
//		throw new std::runtime_error("can't remove last node");
//	node.value = next.value;
//	node.right = next.right;
//}
//
///*
// * 向有序环形链表插入节点
// * 时间复杂度O(N)
// * 空间复杂度O(1)
// */
//Node insertNum(Node head,int data)
//{
//	Node node = new Node(data);
//	if(head == NULL){
//		node.right =node;
//		return node;
//	}
//	Node pre = head;
//	Node cur = head.right;
//	while(cur != head){
//		if(pre.value <= data && data <= cur.value)
//			break;
//		pre = cur;
//		cur = cur.right;
//	}
//	pre.right = node;
//	node.left = pre;
//	node.right = cur;
//	cur.left = node;
//	return head.value < data ? head : node;
//}
//
//
///*
// * 合并两个有序单链表
// * 时间复杂度O(N+M)
// * 空间复杂度O(1)
// */
//Nodes merge(Nodes head1,Nodes head2)
//{
//	if(head1 == NULL || head2 == NULL)
//		return head1 != NULL ? head1 : head2;
//	Nodes head = head1.value < head2.value ? head1 : head2;
//	Nodes cur1 = head == head1 ? head1 : head2;
//	Nodes cur2 = head == head2 ?head2 : head1;
//	Nodes pre = NULL;
//	Nodes next = NULL;
//	while(cur1 != NULL && cur2 != NULL){
//		if(cur1.value < cur2.value){
//			pre = cur1;
//			cur1 = cur1.next;
//		}
//		else{
//			next = cur2.next;
//			pre.next = cur2;
//			cur2.next = cur1;
//			pre = cur2;
//			cur2 = next;
//		}
//	}
//	pre.next = cur1 == NULL ? cur2 : cur1;
//	return head;
//}
//
///*
// * 按照左右半区方式重新组合单链表
// * 时间复杂度O(N)
// * 空间复杂度O(1)
// */
//
//void mergr(Nodes left,Nodes right)
//{
//	Nodes next = NULL;
//	while(left.next != NULL){
//		next = right.next;
//		right.next = left.next;
//		left.next = right;
//		left = right.next;
//		right = next;
//	}
//	left.next = right;
//}
//
//
//void relocate(Nodes head)
//{
//	if(head == NULL || head.next == NULL)
//		return;
//	Nodes mid = head;
//	Nodes right = head.next;
//	while(right.next != NULL && right.next.next != NULL){
//		mid = mid.next;
//		right = right.next.next;
//	}
//	right = mid.next;
//	mid.next = NULL;
//	mergr(head,right);
//
//}
//
//
///*
// * 二叉树前序，中序。后序遍历
// */
//
//void preOrderRecur(Node head)
//{
//	if(head == NULL)
//		return;
//	std::cout<<head.value<<std::endl;
//	preOrderRecur(head.left);
//	preOrderRecur(head.right);
//}
//
//void inOrderRecur(Node head)
//{
//	if(head == NULL)
//		return;
//	inOrderRecur(head.left);
//	std::cout<<head.value<<std::endl;
//	inOrderRecur(head.right);
//}
//
//void posOrderRecur(Node head)
//{
//	if(head == NULL)
//		return;
//	posOrderRecur(head.left);
//	posOrderRecur(head.right);
//	std::cout<<head.value<<std::endl;
//}
//
//void preOrderUnRecur(Node head)
//{
//	std::stack<Node> Stack = new std::stack<Node>();
//	if(head == NULL)
//		return;
//	Stack.push(head);
//	while(!Stack.empty()){
//		Node cur = Stack.top();
//		std::cout<<cur.value<<std::endl;
//		if(cur.right != NULL)
//			Stack.push(cur.right);
//		if(cur.left != NULL)
//			Stack.push(cur.left);
//		Stack.pop();
//	}
//}
//
//void inOrderUnRecur(Node head)
//{
//	std::stack<Node> Stack = new std::stack<Node>();
//	if(head == NULL)
//		return;
//	while(!Stack.empty() || head != NULL){
//		if(head != NULL){
//			Stack.push(head);
//			head = head.left;
//		}
//		else{
//			head = Stack.top();
//			std::cout<<head.value<<std::endl;
//			Stack.pop();
//			head = head.right;
//		}
//	}
//}
//
//void posOrderUnRecur1(Node head)
//{
//	if(head == NULL)
//		return;
//	std::stack<Node> Stack1 = new std::stack<Node>();
//	std::stack<Node> Stack2 = new std::stack<Node>();
//	Stack1.push(head);
//	while(!Stack1.empty){
//		head = Stack1.top();
//		Stack2.push(head);
//		Stack1.pop();
//		if(head.left != NULL)
//			Stack1.push(head.left);
//		if(head.right != NULL)
//			Stack1.push(head.right);
//	}
//	while(!Stack2.empty()){
//		std::cout<<Stack2.top().value<<std::endl;
//		Stack2.pop();
//	}
//}
//
//void posOrderUnRecur2(Node head)
//{
//	if(head == NULL)
//		return;
//	std::stack<Node> Stack = new std::stack<Node>();
//	Stack.push(head);
//	Node c = NULL;
//	while(!Stack.empty()){
//		c = Stack.top();
//		if(c.left != NULL && head != c.left && head != c.right){
//			Stack.push(c.left);
//		}
//		else if(c.right != NULL && head != c.right){
//			Stack.push(c.right);
//		}
//		else{
//			std::cout<<c.value<<std::endl;
//			head = c;
//			Stack.pop();
//		}
//	}
//}
//
///*
// * 打印二叉树的边界节点
// */
//
//int getHeight(Node head,int l)
//{
//	if(head == NULL)
//		return l;
//	return std::max(getHeight(head.left,l+1),getHeight(head.right,l+1));
//}
//
//void setEdgeMap(Node head,int l,Node (*edgeMap)[2])
//{
//	if(head == NULL)
//		return;
//	edgeMap[l][0] = edgeMap[l][0] == NULL ? head : edgeMap[l][0];
//	edgeMap[l][1] = head;
//	setEdgeMap(head.left,l+1,edgeMap);
//	setEdgeMap(head.right,l+1,edgeMap);
//}
//
//void printEdge1(Node head)
//{
//	if(head == NULL)
//		return;
//	int height = getHeight(head,0);
//	Node edgeMap[height][2] = new Node[height][2];
//	setEdgeMap(head,0,edgeMap);
//
//
//}
//
///*
//求最长子串长度及其位置
//*/
//int ChildString(const char* p,int& pos)
//{
//    int begin=0,next=1,maxlen=1,len=0,Len=0,mark=1;
//    char* b = const_cast<char*>(p);
//    while(*b++!='\0')
//        Len++;
//    while(begin<Len)
//    {
//        if(*(p+begin)==*(p+next)&&next<Len)
//        {
//            len++;
//            begin++;
//            next++;
//        }
//        else
//        {
//            mark+=(len+1);
//           // std::cout<<mark<<std::endl;
//            if(len>maxlen)
//            {
//                maxlen=len+1;
//                pos=mark-maxlen;
//                len=0;
//            }
//            else
//            {
//                len=0;
//            }
//            begin++;
//            next++;
//        }
//    }
//    return maxlen;
//}
//
///*
//反转字符串
//*/
//int reverse(const char* src)
//{
//    int len = strlen(src);
//    char* des = new char[len+1];
//    char* d = des;
//    const char* s = &src[len-1];
//    while(len-->0)
//    {
//        *d++ = *s--;
//    }
//    *d=0;
//    std::cout<<des<<std::endl;
//    delete[] des;
//    return 0;
//}
//
//int reverse2(const char* src,std::string& des)
//{
//    std::stack<char> Stack;
//    for(int i = 0;i< strlen(src);i++)
//        Stack.push(src[i]);
//    while(!Stack.empty())
//    {
//        des.push_back(Stack.top());
//        //std::cout<<Stack.top()<<std::endl;
//        Stack.pop();
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

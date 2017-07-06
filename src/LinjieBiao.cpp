/*
 * LinjieBiao.cpp
 *
 *  Created on: 2016年12月3日
 *      Author: wangqi
 */

#include <list>
#include <stack>
#include <queue>

template <typename T>
class Vertext
{
public:
	Vertext(const T& label,int pos):Label(label),HasBeenVisited(false),Pos(pos) {};
	Vertext();
private:
	const T Label;
	const int Pos;
	bool HasBeenVisited;
private:
	typedef T label_type;
};




template <typename Vertext>
class Graph
{
private:
	typedef typename Vertext::label_type  label_type;
public:
	Graph(const int capacity);
	virtual ~Graph();
	void addVertext(const Vertext* data);
	void addEage(int start,int end);
	void BFS();
	void DFS();
	inline label_type showVertext(const int& k) { return VertextList[k]->Label;}
	int GetNextUnVisitedVertext(const int K);
private:
	Vertext** VertextList;
	std::list<int>* HeadNode;
	int capacity;
	int size;
};

template <typename Vertext>
Graph<Vertext>::Graph(const int Capacity)
: capacity(Capacity)
  ,size(0)
{
	VertextList = new Vertext*[capacity];
	HeadNode = new std::list<int>[capacity];
}


template <typename Vertext>
virtual Graph<Vertext>::~Graph()
{
	delete[] VertextList;
	delete[] HeadNode;
}

template <typename Vertext>
void Graph<Vertext>::addVertext(const Vertext* data)
{
	if(size == capacity)
		break;
	if(data->Pos == size)
		VertextList[size++] = data;
}



template <typename Vertext>
void Graph<Vertext>::addEage(int start,int end)
{
	HeadNode[start].push_back(end);
}

template <typename Vertext>
int Graph<Vertext>::GetNextUnVisitedVertext(const int K)
{
	std::list<int> List = &HeadNode[K];
	typedef std::list<int>::iterator Iter;
	Iter head = List.begin();
	for(Iter it = ++head;it != List.end();){
		for(int i = 0;i < size;i++){
			if(VertextList[i]->Pos == *it && VertextList[i]->HasBeenVisited == false)
				return *it;
		}
		return -1;
	}
	return -1;
}

/*
 * @ 广度优先搜索
 * @ 采用队列结构实现
 */
template <typename Vertext>
void Graph<Vertext>::BFS()
{
	std::queue<int> gQueue;
	std::list<int> List = &HeadNode[0];
	typedef std::list<int>::iterator Iter;
	Iter first = List.begin();
	std::cout<<showVertext(*first)<<std::endl;
	gQueue.push(*first);
	int v;
	while(gQueue.size() > 0){
		v = gQueue.front();
		gQueue.pop();
		std::list<int> pList = &HeadNode[v];
		Iter it = pList.begin();
		for(++it;it != List.end();){
			gQueue.push(*it);
			std::cout<<showVertext(*it)<<std::endl;
		}
	}
}


/*
 * @ 深度优先搜索
 * @ 采用堆栈结构实现
 */
template <typename Vertext>
void Graph<Vertext>::DFS()
{
	std::stack<int>  gStack;
	VertextList[0]->HasBeenVisited = true;
	std::cout<<showVertext(0)<<std::endl;
	gStack.push(0);
	int v;
	while(gStack.size() > 0){
		v = GetNextUnVisitedVertext(gStack.top());
		if(v == -1)
			gStack.pop();
		else{
			VertextList[v]->HasBeenVisited = true;
			std::cout<<showVertext(v)<<std::endl;
			gStack.push(v);
		}
	}
	for(int i = 0;i < size;i++)
		VertextList[i]->HasBeenVisited = false;

}
































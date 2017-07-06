/*
 * Hash_Map.cpp
 *
 *  Created on: 2016年12月3日
 *      Author: wangqi
 */

#include <vector>
#include <stdint.h>
#include <exception>
#include <ext/hash_map>
#include <ext/hash_set>
#include <map>  //采用红黑树二叉树映射
using namespace __gnu_cxx;

template <typename Key,typename Value>
class Hash
{
public:
	Hash(int Capacity = 1024):capacity(Capacity),size(0),Array(capacity) {};
	void Push(const Key& k,const Value& v);
	Value& Get(const Key& k);
	uint32_t hash(const Key& k) const ;
private:
	int size;
	int capacity;

	struct Data
	{
		Key  key;
		Value value;
	};

	std::vector<Data> Array;
};

template <typename Key,typename Value>
uint32_t Hash<Key,Value>::hash(const Key& k) const
{
	uint32_t hashValue = 0;
	const char* keyp = reinterpret_cast<const char*>(&k);
	for(int i = 0;i < sizeof(k);i++){
		hashValue = 37*hashValue+keyp[i];
	}
	return hashValue % capacity;
}

template <typename Key,typename Value>
void Hash<Key,Value>::Push(const Key& k,const Value& v)
{
	if(size >= capacity)
		throw std::exception("表满");
	uint32_t Pos = hash(k);
	Array[Pos] = v;
	size++;
}

template <typename Key,typename Value>
Value& Hash<Key,Value>::Get(const Key& k)
{
	if(size == 0)
		throw std::exception("空表");
	uint32_t Pos = hash(k);
	if(Array[Pos].Key == k)
		return Array[Pos];
	else
		return Value();
}




































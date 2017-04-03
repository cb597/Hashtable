#pragma once

#include <utility>
#include <list>
#include <vector>
#include <algorithm>

template <typename Data>
class Hashtable
{
public:
	/// create a hashtable
	/// param size_t : number of buckets
	Hashtable(size_t);

	/// insert an element with given key and value
	bool insert(size_t, Data);

	/// remove a node by key and return value
	Data remove(size_t);

	/// get Data by key
	Data get(size_t);
private:
	/// get a Node by key
	std::pair<size_t, Data> get_node(size_t);

	/// store the data
	std::vector<std::list<std::pair<size_t, Data> > > data;

	/// hash by key
	size_t hash(size_t);
};




template<typename Data>
Hashtable<Data>::Hashtable(size_t num_buckets)
{
	for (size_t i = 0; i < num_buckets; ++i)
	{
		std::list<std::pair<size_t, Data> > list;
		data.push_back(list);
	}
}

template<typename Data>
inline bool Hashtable<Data>::insert(size_t key, Data d)
{
	std::pair<size_t, Data> n(key, d);
	size_t idx = hash(key);
	for (std::pair<size_t, Data> node : data[idx])
	{
		if (node.first == key)
		{
			return false; //key already exists
		}
	}
	data[idx].push_back(n);
	return true;
}

template<typename Data>
inline std::pair<size_t, Data> Hashtable<Data>::get_node(size_t key)
{
	for (std::pair<size_t, Data> node : data[hash(key)])
	{
		if (node.first == key)
		{
			return node;
		}
	}
	throw std::runtime_error("key not in Hashtable");
}

template<typename Data>
inline size_t Hashtable<Data>::hash(size_t key)
{
	std::hash<size_t> hash_fn;
	return hash_fn(key) % data.size();
}

template <typename Data>
inline Data Hashtable<Data>::remove(size_t key)
{
	std::pair<size_t, Data> n = get_node(key);
	data[hash(key)].remove(n);
	return n.second;
}

template<typename Data>
inline Data Hashtable<Data>::get(size_t key)
{
	return get_node(key).second;
}

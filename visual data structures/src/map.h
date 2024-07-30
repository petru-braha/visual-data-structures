#pragma once
typedef unsigned int nat;
// discussion about map VS hash-table
template <class K, class V>
class Map
{
	
protected:
	struct entry
	{
		struct value
		{
			V value_name;
			value* next_val;

			value(const V& next_value):value_name(next_value), next_val(nullptr) {}
			value(const V& next_value, value* nxt):value_name(next_value), next_val(nxt) {}
		};

		K key_name;
		entry* next_key;
		value* first_value;

		entry(const K& key, const V& value_name);

		void add_value(const V& next_value); // checks if the value already exists
		bool exists_value(const V& value);

		void delete_value(const V& value);
		void delete_values_recursive(value*& pointer_head);
		~entry();
	};
	typedef entry* pointer_entry;

	static entry* first_key;
	static entry* pointer_IT; // helps iteration
	
	pointer_entry add_key(const K& key, const V& value);

public:
	struct iterator
	{
		K iterator_key;
		V iterator_value;
		nat iterator_index;
		iterator(const K& key, const V& value, const nat& index);
		iterator operator*() { return { iterator_key, iterator_value, iterator_index }; }
		void operator++();
		bool operator!=(const iterator& second_itr);
	};
	
	Map();
	void Set(const K& key, const V& value) { this->add_key(key, value); }
	bool Get(const K& key, V& value);
	bool Includes(const Map<K, V>& map);
	
	V& operator[](const K& key);
	iterator begin();
	iterator end()const;

	void print(const K& key);
	int  Count()const;
	bool Delete(const K& key);
	void Clear(); // everything
	~Map() { this->Clear(); }
};

// map = multiple keys // key = multiple values
// key == entry

// adding an entry + add a second one null

#pragma once
#include "pch.h"
/*#
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#define MAX 2000

template <class K, class V>
Map<K, V>::pointer_entry Map<K, V>::first_key = nullptr;
template <class K, class V>
Map<K, V>::pointer_entry Map<K, V>::pointer_IT = nullptr;

//---------------------------------------------------------------------
//BASIC OPERATIONS

template <class K, class V>
Map<K, V>::Map()
{
	this->first_key = nullptr;
	this->pointer_IT = nullptr;
}

template <class K, class V>
Map<K, V>::pointer_entry Map<K, V>::add_key(const K& key, const V& value)
{
	if (this->first_key == nullptr)
	{
		this->first_key = new entry(key, value);
		this->first_key->next_key = new entry(NULL, NULL);
		return this->first_key;
	}

	entry* it = this->first_key;
	while (it)
	{
		if (it->key_name == key)
		{
			if(value)
				it->add_value(value);
			return it;
		}

		entry* nxt = it->next_key;
		if (nxt->key_name == NULL)
		{
			delete nxt;
			it->next_key = new entry(key, value);
			nxt = it->next_key;
			nxt->next_key = new entry(NULL, NULL);
			return nxt;
		}
		it = it->next_key;
	}
	return nullptr;
}

template <class K, class V>
bool Map<K, V>::Get(const K& key, V& value)
{
	entry* it = this->first_key;
	while (it)
	{
		if (it->key_name == key)
		{
			it->add_value(value);
			return true;
		}
		it = it->next_key;
	}
	return false;
}

template <class K, class V>
bool Map<K, V>::Includes(const Map<K, V>& map)
{
	entry* it = this->first_key;
	entry* second_it = map.first_key;

	if (it == nullptr)
	{
		if (second_it == nullptr)
			return true;
		return false;
	}
	if (second_it == nullptr) return true;

	// not sorted
	while (second_it)
	{
		it = this->first_key;
		while(it->key_name != second_it->key_name)
			it = it->next_key;
		if (it == nullptr)
			return false;

		//check for values - later
		second_it = second_it->next_key;
	}
	return true;
}

//---------------------------------------------------------------------
//CONCRETE OPERATIONS

template <class K, class V>
V& Map<K, V>::operator[](const K& key)
{
	Map<K, V>::entry* it = this->add_key(key, NULL);
	return it->first_value->value_name;
}

template <class K, class V>
Map<K, V>::iterator Map<K, V>::begin()
{
	if (this->first_key == nullptr)
	{
		//return iterator(NULL, NULL, 0);
		printf("error: uninitialised map.\n");
		exit(3);
	}

	pointer_IT = first_key;
	return iterator(this->first_key->key_name, this->first_key->first_value->value_name, 0);
}

template <class K, class V>
Map<K, V>::iterator Map<K, V>::end()const
{
	entry* last_entry = this->first_key;

	nat how_many = 0;
	while (last_entry != nullptr)
	{
		how_many++;
		last_entry = last_entry->next_key;
	}
	return iterator(NULL, NULL, how_many-1);
}

//---------------------------------------------------------------------
//CLEAN-UP OPERATIONS

template <class K, class V>
int Map<K, V>::Count()const
{
	entry* it = this->first_key;
	int how_many = 0;
	while (it)
	{
		how_many++;
		it = it->next_key;
	}
	return how_many;
}

template <class K, class V>
bool Map<K, V>::Delete(const K& key)
{
	if (this->first_key == nullptr)
		return false;

	entry* it = this->first_key, * nxt = it->next_key;
	if (it->key_name == key)
	{
		this->first_key = nxt;
		delete it;
		return true;
	}
	while (nxt)
	{
		if (nxt->key_name == key)
		{
			entry* temp = nxt;
			nxt = nxt->next_key;
			it->next_key = nxt;
			delete temp;
			return true;
		}

		it = nxt;
		nxt->next_key;
	}
	return false;
}

template <class K, class V>
void Map<K, V>::Clear()

	while (this->first_key)
		this->Delete(this->first_key->key_name);
}

template <class K, class V>
void Map<K, V>::print(const K& key)
{
	entry* it = this->first_key;
	V jeje = NULL;
	while (it)
	{
		if (it->key_name == key)
		{
			jeje = it->first_value->value_name;
			break;
		}
		it = it->next_key;
	}

	std::cout << jeje;
}*/
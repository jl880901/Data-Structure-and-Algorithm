/*
 * HashTable.h
 *
 *  Created on: 2017Äê5ÔÂ19ÈÕ
 *      Author: lajiao
 */

#ifndef SRC_HASHTABLE_H_
#define SRC_HASHTABLE_H_

#include <vector>
#include <functional>
#include "HashTableNode.h"

using namespace std;

static const int num_primes = 28;
static const unsigned long primes_list[num_primes] = {
		53ul, 			97ul, 			193ul, 			389ul, 			769ul,
		1543ul, 		3079ul, 		6151ul, 		12289ul, 		24593ul,
		49157ul, 		98317ul,		196613ul, 		393241ul, 		786433ul,
		1572869ul, 		3145739ul, 		6291469ul,		12582917ul, 	25165843ul,
		50331653ul, 	100663319ul, 	201326611ul,	402653189ul, 	805306457ul,
		1610612741ul, 	3221225473ul, 	4294967291ul
};

inline unsigned long next_prime(unsigned long num){
	const unsigned long * first = primes_list;
	const unsigned long * last = primes_list + num_primes;
	const unsigned long * pos = lower_bound(first, last, num);
	return pos == last ? *(last - 1) : *pos;
}

template<class K, class V> class HashTable;

template<class K, class V>
struct HashTable_Iterator{
	typedef HashTable<K, V> hashtable;
	typedef HashTableNode<K, V> htNode;
	typedef HashTable_Iterator<K, V> iterator;
	typedef unsigned long size_type;

	hashtable *ht;
	htNode *cur;

	HashTable_Iterator(htNode *n, hashtable *t): cur(n), ht(t) {};
	HashTable_Iterator(): cur(nullptr), ht(nullptr) {};

	pair<K, V> operator* () {
		return make_pair(cur->key, cur->value);
	}

	pair<K, V>* operator-> () {
		return &(operator*());
	}

	bool operator== (const iterator& it) const {
		return cur == it.cur;
	}

	bool operator!= (const iterator& it) const {
		return cur != it.cur;
	}

	iterator& operator++ (){
		const htNode* old = cur;
		cur = cur->next;
		if(!cur){
			size_type pos = ht->bucket_position(old->key);
			while(!cur && ++pos < ht->bucket_count()){
				cur = ht->buckets[pos];
			}
		}
		return *this;
	}

	iterator& operator++ (int){
		iterator temp = *this;
		++*this;
		return temp;
	}
};

template<class K, class V>
class HashTable {
public:
	typedef HashTableNode<K, V> htNode;
	typedef unsigned long size_type;
	typedef HashTable_Iterator<K, V> iterator;
	HashTable():num_elements(0) {
		initialize_buckets(0);
	};
	HashTable(size_type n):num_elements(0){
		initialize_buckets(n);
	}
	virtual ~HashTable(){
		clear();
	}

private: ////members
	vector<htNode*> buckets;
	int num_elements;
	double load_factor; // num_elements / buckets.size();
	equal_to<K> equals;
	hash<K> hasher;

public:
	friend struct HashTable_Iterator<K, V>;

private:
	size_type next_size(size_type num) const {
		return next_prime(num);
	}

	void initialize_buckets(size_type num){
		const size_type num_buckets = next_size(num);
		buckets.reserve(num_buckets);
		buckets.insert(buckets.end(), num_buckets, nullptr);
		num_elements = 0;
		load_factor = 2.0;
	}

	htNode* new_node(const K key, const V value){
		htNode* new_node = new htNode(key, value);
		return new_node;
	}

	void delete_node(htNode* node){
		delete node;
	}

public:

	iterator insert_unique(const K &key, const V &val){
		resize(num_elements + 1);
		return insert_unique_noresize(key, val);
	}

	void resize(size_type num){
		const size_type old_bucket_size = buckets.size();
		if(num > (old_bucket_size * load_factor)){ // need to resize;
			const size_type new_bucket_size = next_size(old_bucket_size + 1); // reconstruct bucket
			if(new_bucket_size > old_bucket_size){
				vector<htNode*> temp(new_bucket_size, (htNode*)0);
				for(size_type i = 0; i < old_bucket_size; i++){
					htNode* first_node = buckets[i];
					while(first_node){
						size_type new_pos = bucket_position(first_node->key, new_bucket_size);
						buckets[i] = first_node->next;
						first_node->next = temp[new_pos];
						temp[new_pos] = first_node;
						first_node = buckets[i];
					}
				}
				buckets.swap(temp);
			}
		}
	}

	iterator insert_unique_noresize(const K &key, const V &val){
		const size_type pos = bucket_position(key, buckets.size());
		htNode* first_node = buckets[pos];

		while(first_node){
			if(equals(first_node->key, key)){
				first_node->value = val;
				return iterator(first_node, this);
			}
			first_node = first_node->next;
		}
		htNode* new_node = new htNode(key, val);
		new_node->next = first_node;
		buckets[pos] = new_node;
		num_elements++;
		return iterator(new_node, this);
	}

	size_type bucket_position(K key) const{
		return bucket_position(key, buckets.size());
	}

	size_type bucket_position(K key, size_type n) const{
		// TODO:
		return hasher(key) % n;
	}

	void clear(){
		for(size_type i = 0; i < buckets.size(); i++){
			htNode* cur = buckets[i];
			while(cur){
				htNode* temp = cur->next;
				delete_node(cur);
				cur = temp;
			}
			buckets[i] = nullptr;
		}
		num_elements = 0;
	}

	size_type size(){
		return num_elements;
	}

	size_type max_bucket_count(){
		return primes_list[num_primes - 1];
	}

	iterator begin(){
		for(size_type i = 0; i < buckets.size(); i++){
			if(buckets[i])
				return iterator(buckets[i], this);
		}
		return end();
	}

	iterator end(){
		return iterator(nullptr, this);
	}

	iterator find(const K &key){
		size_type pos = bucket_position(key);
		htNode *cur = buckets[pos];
		while(cur && !equals(cur->key, key)){
			cur = cur->next;
		}
		return iterator(cur, this);
	}

	iterator find_or_insert(const K &key){
		resize(num_elements + 1);
		size_type pos = bucket_position(key);

		htNode *first = buckets[pos];
		htNode *cur = first;
		while(cur){
			if(equals(cur->key, key))
				return iterator(cur, this);
			cur = cur->next;
		}
		// not found
		htNode *new_node = new htNode(key, V());
		new_node->next = first;
		buckets[pos] = new_node;
		num_elements++;
		return iterator(new_node, this);
	}

	V& operator[] (const K& key){
		return find_or_insert(key).cur->value;
	}
public:
	size_type bucket_count() const {
		return buckets.size();
	}
};

#endif /* SRC_HASHTABLE_H_ */

template<class K, class V>
class HashTableNode{
public:
	HashTableNode(const K &key, const V &value):
		key(key), value(value), next(nullptr) {
	}

	~HashTableNode(){
	//JL - TODO;
	}

	K getKey() const {
		return key;
	}

	void setKey(K key) {
		this->key = key;
	}

	const HashTableNode*& getNext() const {
		return next;
	}

	void setNext(const HashTableNode*& next) {
		this->next = next;
	}

	V getValue() const {
		return value;
	}

	void setValue(V value) {
		this->value = value;
	}

public:
	K key;
	V value;
	HashTableNode *next;
};

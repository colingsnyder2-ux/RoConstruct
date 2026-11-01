// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Value {
    unsigned int data[3];

    Value(const Value& other) { copy(other); }
    virtual ~Value();

    void copy(const Value&);
    void clear();
};

struct Node {
    unsigned int key;
    unsigned int hash;
    Value value;
    Node* next;

    Node(unsigned int, Value, unsigned int, Node*);
};

struct Table {
    unsigned int reserved;
    int count;
    Node** buckets;
    int bucketCount;

    void resize(int);
    void set(const unsigned int&, const Value&);
};

void Table::set(const unsigned int& key, const Value& value)
{
    unsigned int hash = key;
    unsigned int bucket = hash % bucketCount;
    Node* node = buckets[bucket];

    if (!node) {
        buckets[bucket] = new Node(key, value, hash, 0);
        ++count;
        return;
    }

    int length = 1;
    bool sameHash = true;

    do {
        sameHash = sameHash && hash == node->key;

        if (hash == node->key && node->hash == hash) {
            Value* destination = &node->value;
            if (destination != &value) {
                destination->clear();
                destination->copy(value);
            }
            return;
        }

        node = node->next;
        ++length;
    } while (node);

    if ((length > 5) & !sameHash) {
        if (bucketCount < count * 20)
            resize(bucketCount * 2 + 1);
    }

    bucket = hash % bucketCount;
    buckets[bucket] = new Node(key, value, hash, buckets[bucket]);
    ++count;
}

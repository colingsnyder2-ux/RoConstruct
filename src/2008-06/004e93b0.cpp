// from server: 100% by king_originala
extern void *valueTable;
void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Value {
    void *table;
    unsigned int data[3];

    Value(const Value &);
    ~Value();
    void copy(const Value &);
    void clear();
};

inline Value::Value(const Value &other) : table(&valueTable)
{
    copy(other);
}

struct Node {
    unsigned int key;
    unsigned int hash;
    Value value;
    Node *next;

    Node(unsigned int, Value, unsigned int, Node *);
};

struct S {
    unsigned int reserved;
    int count;
    Node **buckets;
    unsigned int bucketCount;

    void resize(unsigned int);
    void f(const unsigned int &, const Value &);
};

void S::f(const unsigned int &key, const Value &value)
{
    unsigned int hash = key;
    unsigned int index = hash % bucketCount;
    Node *node = buckets[index];

    if (!node) {
        buckets[index] = new Node(key, value, hash, 0);
        ++count;
        return;
    }

    int length = 1;
    bool sameHash = true;
    do {
        sameHash = sameHash && hash == node->key;
        if (hash == node->key && node->hash == hash) {
            if (&node->value != &value) {
                node->value.clear();
                node->value.copy(value);
            }
            return;
        }
        node = node->next;
        ++length;
    } while (node);

    if ((!sameHash & (length > 5)) &&
        (int)bucketCount < count * 20) {
        resize(bucketCount * 2 + 1);
    }

    index = hash % bucketCount;
    buckets[index] = new Node(key, value, hash, buckets[index]);
    ++count;
}

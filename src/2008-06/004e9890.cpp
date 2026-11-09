// from server: 100% by king_originala
typedef unsigned int UInt;

extern void *valueTable;
void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Value {
    void *table;
    unsigned int data[3];

    Value(const Value &other) : table(&valueTable) {
        copy(&other);
    }

    ~Value();
    void __thiscall copy(const Value *);
    void __thiscall release();
};

struct Node {
    UInt key;
    UInt hash;
    Value value;
    Node *next;

    Node(UInt, Value, UInt, Node *);
};

struct S {
    int unused;
    int count;
    Node **buckets;
    int bucketCount;

    void __thiscall resize(int);
    void __thiscall f(const UInt &, const Value &);
};

void S::f(const UInt &key, const Value &value)
{
    UInt hash = key;
    UInt bucket = hash % bucketCount;
    Node *node = buckets[bucket];

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
            Value *destination = &node->value;
            if (destination != &value) {
                destination->release();
                destination->copy(&value);
            }
            return;
        }

        node = node->next;
        ++length;
    } while (node);

    if ((!sameHash) & (length > 5)) {
        if (bucketCount < count * 20)
            resize(bucketCount * 2 + 1);
    }

    bucket = hash % bucketCount;
    buckets[bucket] = new Node(key, value, hash, buckets[bucket]);
    ++count;
}

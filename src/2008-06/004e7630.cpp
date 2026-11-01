// from server: 100% by king_originala
#pragma float_control(precise, off)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Vector {
    float x, y, z;

    Vector(const Vector& v) : x(v.x), y(v.y), z(v.z) {}
    unsigned int hash() const;
};

struct Reference {
    void* object;
    Reference(const Reference&);
    ~Reference();
};

struct Value {
    Reference item[1];
    Value& operator=(const Value&);
};

struct Node {
    unsigned int hash;
    Vector key;
    Value value;
    Node* next;

    Node(Vector, Value, unsigned int, Node*);
};

struct S {
    int unused;
    int count;
    Node** buckets;
    int bucketCount;

    void resize(int);
    void f(const Vector&, const Value&);
};

void S::f(const Vector& key, const Value& value)
{
    unsigned int hash = key.hash();
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
        sameHash = sameHash && hash == node->hash;

        if (hash == node->hash &&
            node->key.x == key.x &&
            node->key.y == key.y &&
            node->key.z == key.z) {
            node->value = value;
            return;
        }

        node = node->next;
        ++length;
    } while (node);

    if (int(!sameHash) & int(length > 5)) {
        if (bucketCount < count * 20)
            resize(bucketCount * 2 + 1);
    }

    bucket = hash % bucketCount;
    buckets[bucket] = new Node(key, value, hash, buckets[bucket]);
    ++count;
}

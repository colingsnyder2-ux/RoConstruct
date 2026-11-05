// from server: 100% by king_originala
extern char valueTable;

struct Value
{
    void *table;
    unsigned int data[3];

    Value(const Value &);
    ~Value();
    void copy(const Value &);
};

inline Value::Value(const Value &other)
{
    table = &valueTable;
    copy(other);
}

struct Node
{
    unsigned int key;
    unsigned int hash;
    Value value;
    Node *next;

    Node(unsigned int, Value, unsigned int, Node *);
};

struct S
{
    unsigned int reserved;
    int count;
    Node **buckets;
    int bucketCount;

    void resize(int);
    void f(const unsigned int *, const Value &);
};

void S::f(const unsigned int *key, const Value &value)
{
    unsigned int hash = *key;
    unsigned int bucket = hash % bucketCount;
    Node *node = buckets[bucket];

    if (!node)
    {
        buckets[bucket] = new Node(*key, value, hash, 0);
        ++count;
        return;
    }

    int length = 1;
    bool sameHash = true;
    do
    {
        sameHash = sameHash && hash == node->key;
        if (hash == node->key && node->hash == hash)
        {
            if (&node->value != &value)
            {
                node->value.~Value();
                node->value.copy(value);
            }
            return;
        }
        node = node->next;
        ++length;
    } while (node);

    if ((!sameHash) & (length > 5))
    {
        if (bucketCount < count * 20)
            resize(bucketCount * 2 + 1);
    }

    bucket = hash % bucketCount;
    buckets[bucket] = new Node(*key, value, hash, buckets[bucket]);
    ++count;
}

// from server: 100% by king_originala
extern char valueTag;

void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Value {
    void *tag;
    unsigned int data[3];

    Value(const Value &);
    void copy(const Value &);
    void clear();
};

inline Value::Value(const Value &other) : tag(&valueTag)
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

struct Table {
    int unused;
    int count;
    Node **buckets;
    int capacity;

    void resize(int);
    void set(const unsigned int &, const Value &);
};

void Table::set(const unsigned int &key, const Value &value)
{
    unsigned int hash = key;
    unsigned int bucket = hash % capacity;
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
            if (&node->value != &value) {
                node->value.clear();
                node->value.copy(value);
            }
            return;
        }

        node = node->next;
        ++length;
    } while (node);

    if ((!sameHash) & (length > 5)) {
        if (capacity < count * 20)
            resize(capacity * 2 + 1);
    }

    bucket = hash % capacity;
    buckets[bucket] = new Node(key, value, hash, buckets[bucket]);
    ++count;
}

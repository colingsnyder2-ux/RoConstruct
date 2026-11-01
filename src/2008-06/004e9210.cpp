// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern void* valueTable[];

struct Value
{
    void* table;
    unsigned int data[3];

    Value(const Value&);
    ~Value();
    void copy(const Value&);
    void release();
};

inline Value::Value(const Value& other) : table(valueTable)
{
    copy(other);
}

inline Value::~Value()
{
    release();
}

struct Entry
{
    unsigned int key;
    unsigned int hash;
    Value value;
    Entry* next;

    Entry(unsigned int, Value, unsigned int, Entry*);
};

struct S
{
    unsigned int reserved;
    int size;
    Entry** buckets;
    int bucketCount;

    void resize(int);
    void f(const unsigned int&, const Value&);
};

void S::f(const unsigned int& key, const Value& value)
{
    unsigned int hash = key;
    unsigned int bucket = hash % bucketCount;
    Entry* entry = buckets[bucket];

    if (!entry) {
        buckets[bucket] = new Entry(key, value, hash, 0);
        ++size;
        return;
    }

    int length = 1;
    bool sameHash = true;

    do {
        sameHash = sameHash && hash == entry->key;

        if (hash == entry->key && entry->hash == hash) {
            Value* destination = &entry->value;
            if (destination != &value) {
                destination->release();
                destination->copy(value);
            }
            return;
        }

        entry = entry->next;
        ++length;
    } while (entry);

    if ((!sameHash) & (length > 5)) {
        if (bucketCount < size * 20)
            resize(bucketCount * 2 + 1);
    }

    bucket = hash % bucketCount;
    buckets[bucket] = new Entry(key, value, hash, buckets[bucket]);
    ++size;
}

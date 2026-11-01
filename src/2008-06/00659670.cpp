// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Key {
    unsigned int a, b, c;
};

struct Node {
    char padding[28];
    Key key;
    Node* next;
};

struct Entry {
    unsigned int value;
    Node* node;
};

struct Bucket {
    char padding[12];
    Entry* begin;
    Entry* end;
    Entry* capacity;
};

struct S {
    char padding[12];
    Bucket buckets[1];
    Node* find(unsigned int bucket, unsigned int index, const Key& key);
};

Node* S::find(unsigned int bucket, unsigned int index, const Key& key)
{
    Bucket& b = buckets[bucket];
    if (index >= static_cast<unsigned int>(b.end - b.begin))
        invalid_parameter_noinfo();

    Node* p = b.begin[index].node;
    while (p) {
        if (p->key.a == key.a &&
            p->key.b == key.b &&
            p->key.c == key.c)
            return p;
        p = p->next;
    }
    return 0;
}

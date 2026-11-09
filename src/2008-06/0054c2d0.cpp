// from server: 100% by king_originala
typedef unsigned int Key;

struct Pair {
    Key first;
    int second;

    Pair(const Key&, const int&);
};

struct Iterator {
    void* node;
    void* owner;

    bool operator==(const Iterator&) const;
    void* getNode() const;
    Pair* dereference() const;
};

struct Compare {
    bool operator()(const Key&, const Key&) const;
};

extern const Key& __cdecl getKey(void*);

struct Mesh {
    unsigned char reserved[8];
    Compare compare;

    Iterator find(const Key&);
    Iterator end();
    Iterator insert(Iterator, const Pair&);
    int* f(const Key&);
};

#pragma optimize("", off)
int* Mesh::f(const Key& key)
{
    Iterator it = find(key);
    if (it == end() || compare(key, getKey(it.getNode())))
        it = insert(Iterator(it), Pair(key, 0));
    return &it.dereference()->second;
}
#pragma optimize("", on)

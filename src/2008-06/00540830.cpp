// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma strict_gs_check(on)
#pragma optimize("", off)

struct Node;

struct Iterator {
    void* container;
    void* current;

    bool equal(const Iterator& other) const;
    Node* position() const;
    Node* node() const;
};

struct Temporary {
    unsigned int value;

    Temporary();
    ~Temporary();
};

struct Entry {
    unsigned int data[4];

    Entry(const unsigned int& key, const Temporary& value);
    ~Entry();
};

struct Filter {
    bool accept(const unsigned int& key, unsigned int value);
};

extern "C" unsigned int __cdecl classify(Node* node);

struct Bucket {
    unsigned char padding[8];
    Filter filter;

    Iterator find(const unsigned int& key);
    Iterator end();
    Iterator insert(Iterator hint, const Entry& value);
    void* f(const unsigned int& key);
};

void* Bucket::f(const unsigned int& key)
{
    Iterator it = find(key);
    if (it.equal(end()) || filter.accept(key, classify(it.position()))) {
        it = insert(Iterator(it), Entry(key, Temporary()));
    }
    return reinterpret_cast<unsigned char*>(it.node()) + 12;
}

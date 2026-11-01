// from server: 100% by king_originala
struct Entry {
    unsigned int data[2];
};

struct Entries {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Object {
    char padding[0x154];
    Entries* entries;
};

struct Handle {
    Object* get(int);
};

struct CopyVerb {
    char padding[0x14];
    Handle handle;
    int f();
};

int CopyVerb::f()
{
    Entries* p = handle.get(1)->entries;
    return (unsigned int)(p->last - p->first) > 0;
}

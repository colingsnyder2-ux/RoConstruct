// from server: 100% by king_originala
struct Entry {
    char data[64];
};

struct Container {
    char padding[12];
    Entry* first;
    Entry* last;

    int lookup(unsigned int index);
};

struct S {
    char padding[92];
    Container entries;

    int f();
};

int S::f()
{
    Container* container = &entries;
    unsigned int count =
        static_cast<unsigned int>(container->last - container->first);
    if (count > 0)
        return container->lookup(0);
    return 0;
}

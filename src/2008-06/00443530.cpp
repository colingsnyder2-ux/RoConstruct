// from server: 100% by king_originala
struct Accessor {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual int get(void*) = 0;
};

struct S {
    unsigned char padding[0x18];
    Accessor* accessor;
    bool f(void*, void*);
};

bool S::f(void* first, void* second)
{
    int value = accessor->get(first);
    return value == accessor->get(second);
}

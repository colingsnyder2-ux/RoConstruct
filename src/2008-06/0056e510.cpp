// from server: 100% by king_originala
struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual void get(void** result, void* source);
};

extern void __cdecl copyValue(void* destination, const void* source);

struct S
{
    unsigned char padding[24];
    Accessor* accessor;
    void* f(void* destination, void* source);
};

void* S::f(void* destination, void* source)
{
    volatile unsigned long temporary = 0;
    accessor->get(&source, source);
    copyValue(destination, &source);
    return destination;
}

// from server: 100% by king_originala
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void* get(void*);
};

extern "C" void __cdecl convert(void*, void**);

struct S {
    unsigned char padding[24];
    Accessor* accessor;
    void* f(void* result, void* object);
};

void* S::f(void* result, void* object)
{
    volatile unsigned int unused = 0;
    object = accessor->get(object);
    convert(result, &object);
    return result;
}

// from server: 100% by king_originala
extern "C" void* (__cdecl *malloc)(unsigned int);
extern "C" void __cdecl free(void*);

inline void* __cdecl operator new(unsigned int size) throw()
{
    return malloc(size);
}

inline void __cdecl operator delete(void* p) throw()
{
    free(p);
}

struct TypedMemItem
{
    char storage[0x160];
    TypedMemItem(int value);
};

struct Deleter
{
    int value;

    Deleter() : value(0)
    {
        *(volatile unsigned char*)&value = 0;
    }

    void operator()(TypedMemItem* p) const;
};

struct S
{
    S(TypedMemItem* p, Deleter deleter);
    static S f(int value);
};

S S::f(int value)
{
    Deleter deleter;
    return S(new TypedMemItem(value), deleter);
}

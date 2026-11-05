// from server: 40% by atomic.potato
struct S
{
    unsigned char f(unsigned char, void*);
};

unsigned char S::f(unsigned char value, void* p)
{
    void* q = 0;
    if (p != (void*)(&p))
    {
        q = *(void**)p;
        *(void**)p = 0;
    }

    if (q)
    {
        void** vtable = *(void***)q;
        typedef void (__thiscall *Fn)(void*, int);
        ((Fn)(*vtable))(q, 1);
    }

    return value;
}

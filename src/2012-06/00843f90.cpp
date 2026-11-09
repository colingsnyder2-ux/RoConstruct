// from server: 100% by atomic.potato
extern "C" void* __cdecl primitive(void*, int, void*);

struct S
{
};

int __cdecl f(void* p)
{
    void* q = primitive(p, 1, *(void**)0xde13b4);
    void** v = *(void***)q;
    typedef void (__thiscall *Fn)(void*, int);
    ((Fn)v[0])(q, 0);
    return 0;
}

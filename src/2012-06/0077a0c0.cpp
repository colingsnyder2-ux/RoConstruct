// from server: 96% by atomic.potato
typedef unsigned int uint32;

extern "C" void __cdecl HashCode(const void*);

struct S
{
    int f();
};

int S::f()
{
    uint32 p = *(uint32*)((char*)this + 12);
    HashCode((const void*)p);
    if (p)
    {
        uint32 v = *(uint32*)(p + 24);
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = *(Fn*)v;
        fn((void*)(p + 24), 1);
    }
    return 0;
}

// from server: 76% by atomic.potato
struct S
{
};

void __cdecl f(void* a, void* b)
{
    typedef void (__thiscall *Fn)(void*, void*);
    Fn fn = *(Fn*)a;
    fn(*(void**)((char*)a + 4), b);
}

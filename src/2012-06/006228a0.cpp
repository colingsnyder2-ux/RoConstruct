// from server: 64% by atomic.potato
struct S
{
    void* f();
};

extern "C" void* __cdecl fn_52aa40();
struct T
{
    int f(void*);
};
extern "C" int __cdecl fn_6c8100(void*, void*);

void* S::f()
{
    void* p;
    void* q;

    p = *((void**)((char*)this + 8));
    if (p == 0)
        return 0;

    q = *((void**)((char*)p + 12));
    if (fn_6c8100(q, fn_52aa40()) == 0)
        return 0;

    return (char*)p - 28;
}

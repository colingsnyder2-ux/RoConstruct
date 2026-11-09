// from server: 100% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);

struct S
{
    void* f();
};

void* S::f()
{
    void* p = operator_new(0x3c);
    if (p)
        *(void**)p = p;
    void** q = (void**)((char*)p + 4);
    if (q)
        *q = p;
    return p;
}

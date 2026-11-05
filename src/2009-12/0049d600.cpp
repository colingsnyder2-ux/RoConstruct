// from server: 60% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void initialize(void*, void*, void*);

struct S
{
};

void* __cdecl f(void* a, void* b)
{
    void* p = operator_new(0x20);
    if (p != 0)
        initialize(p, a, b);
    return p;
}

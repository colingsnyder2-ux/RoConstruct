// from server: 72% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);

extern "C" void* __cdecl construct(void*, void*, void*);

struct S
{
};

void* __cdecl f(void* a, void* b)
{
    void* p = operator_new(0x20);
    if (p)
        return construct(p, a, b);
    return 0;
}

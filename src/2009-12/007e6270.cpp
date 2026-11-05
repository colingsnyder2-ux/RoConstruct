// from server: 89% by atomic.potato
extern "C" void* __cdecl allocate_raw_heap_memory(unsigned int);

struct S
{
    void* f();
};

void* S::f()
{
    void* p = allocate_raw_heap_memory(4);
    if (p)
        *(unsigned int*)p = 0x009eff84;
    else
        return 0;
    return p;
}

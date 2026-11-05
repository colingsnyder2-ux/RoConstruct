// from server: 76% by atomic.potato
extern "C" void* __cdecl allocate_raw_heap_memory(unsigned int);

struct S_func_007fbc00
{
    void* f();
};

void* S_func_007fbc00::f()
{
    void* p = allocate_raw_heap_memory(4);
    if (!p)
        return 0;
    *(void**)p = (void*)0x00abf750;
    return p;
}

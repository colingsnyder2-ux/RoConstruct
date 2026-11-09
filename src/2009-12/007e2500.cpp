// from server: 73% by atomic.potato
extern "C" void* __cdecl allocate_raw_heap_memory(unsigned int);

struct S {
    void* f();
};

void* S::f()
{
    void* p = allocate_raw_heap_memory(4);
    if (p)
        *(unsigned long*)p = 0x9efd70;
    return p;
}

// from server: 73% by atomic.potato
extern "C" void* __cdecl boost_allocate_raw_heap_memory(unsigned int);

struct S
{
    void* f();
};

void* S::f()
{
    void* p = boost_allocate_raw_heap_memory(4);
    if (p)
        *(unsigned int*)p = 0x9ce9e4;
    return p;
}

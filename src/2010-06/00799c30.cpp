// from server: 73% by atomic.potato
extern "C" void* __cdecl boost_allocate_raw_heap_memory(unsigned int);

struct ExclusiveArbiter
{
    void* f();
};

void* ExclusiveArbiter::f()
{
    void* p = boost_allocate_raw_heap_memory(4);
    if (p)
        *(void**)p = (void*)0x00a542b8;
    return p;
}

// from server: 79% by atomic.potato
extern "C" void* __cdecl boost_allocate_raw_heap_memory(unsigned int);

void* f()
{
    void* p = boost_allocate_raw_heap_memory(4);
    if (p)
        *(unsigned int*)p = 0x9f0048;
    return 0;
}

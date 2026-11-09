// from server: 79% by atomic.potato
extern "C" void* __cdecl allocate_raw_heap_memory(unsigned int);

void* f()
{
    void* p = allocate_raw_heap_memory(4);
    if (p)
        *(unsigned int*)p = 0x00A543CC;
    return 0;
}

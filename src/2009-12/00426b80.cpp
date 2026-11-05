// from server: 89% by atomic.potato
extern "C" void* __cdecl boost_allocate_raw_heap_memory(unsigned int);

void* func_00426b80()
{
    void* p = boost_allocate_raw_heap_memory(4);
    if (p)
        *(unsigned int*)p = 0x9a3964;
    else
        return 0;
    return p;
}

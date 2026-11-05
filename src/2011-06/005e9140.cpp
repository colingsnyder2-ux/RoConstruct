// from server: 89% by atomic.potato
extern "C" void* __cdecl boost_allocate_raw_heap_memory(unsigned int);

void* func_005e9140()
{
    void* p = boost_allocate_raw_heap_memory(4);
    if (p)
        *(void**)p = (void*)0x00a91074;
    else
        return 0;
    return p;
}

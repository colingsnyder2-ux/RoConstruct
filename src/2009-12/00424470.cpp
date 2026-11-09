// from server: 76% by atomic.potato
extern "C" void* __cdecl boost_allocate_raw_heap_memory(unsigned int);

struct ThreadLogManager
{
    void* f();
};

void* ThreadLogManager::f()
{
    void* p = boost_allocate_raw_heap_memory(4);
    if (!p)
        return 0;
    *(unsigned int*)p = 0x9a3818;
    return p;
}

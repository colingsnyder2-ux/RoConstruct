// from server: 100% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);

struct ThreadLogManager
{
    void* f();
};

void* ThreadLogManager::f()
{
    void* p = operator_new(0x148);
    if (p)
        *(void**)p = p;
    void* q = (char*)p + 4;
    if (q)
        *(void**)q = p;
    return p;
}

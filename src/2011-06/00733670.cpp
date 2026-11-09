// from server: 100% by atomic.potato
extern "C" void* __cdecl G1_func_0080a05e(unsigned int);

void* func_00733670()
{
    void* p = G1_func_0080a05e(44);
    if (p)
        *(void**)p = p;
    void* q = (char*)p + 4;
    if (q)
        *(void**)q = p;
    return p;
}

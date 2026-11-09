// from server: 39% by atomic.potato
extern "C" void* __stdcall HeapReAlloc(void*, unsigned int, unsigned int);

struct CXTIconHandle
{
    void* f0;
    void* f4;
    void* method0(void*);
    void* method1(void*);
    void* func_00903797(void*, void*);
};

void* CXTIconHandle::func_00903797(void* a, void* b)
{
    if (a == 0)
    {
        return method0(b);
    }
    if (b == 0)
    {
        method1(a);
        return 0;
    }
    return HeapReAlloc(f4, (unsigned int)a, (unsigned int)b);
}

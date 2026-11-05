// from server: 59% by atomic.potato
extern "C" int __stdcall HeapDestroy(void*);

struct CXTIconHandle
{
    void* heap;
    void* reserved;
    unsigned char active;
    int f();
};

int CXTIconHandle::f()
{
    if (active)
        HeapDestroy(heap);
    return 0;
}

// from server: 52% by atomic.potato
extern "C" void* __stdcall HeapAlloc(void*, unsigned long, unsigned long);

struct CXTIconHandle
{
    void* f(unsigned long);
};

void* CXTIconHandle::f(unsigned long size)
{
    return HeapAlloc(*(void**)((char*)this + 4), 0, size);
}

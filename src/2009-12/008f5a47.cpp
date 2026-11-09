// from server: 53% by atomic.potato
extern "C" unsigned long __stdcall HeapSize(void*, unsigned long, void*);

struct CXTIconHandle {
    void* heap;
    unsigned long f(void*);
};

unsigned long CXTIconHandle::f(void* block)
{
    return HeapSize(0, (unsigned long)this->heap, block);
}

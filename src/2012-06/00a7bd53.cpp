// from server: 38% by atomic.potato
extern "C" void* __stdcall HeapReAlloc(void*, unsigned long, void*, unsigned long);

struct CXTIconHandle {
    void* m_p;
    void* m_hHeap;
    void* method0(void*);
    void* method1(void*);
    void* method2(void*, void*);
};

void* CXTIconHandle::method2(void* a, void* b) {
    if (a == 0) {
        return method0(b);
    }
    if (b == 0) {
        method1(a);
        return 0;
    }
    return HeapReAlloc(m_hHeap, 0, a, (unsigned long)b);
}

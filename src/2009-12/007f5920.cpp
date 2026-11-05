// from server: 83% by atomic.potato
// roc 2009-12 007f5920  unit: ActiveDocView  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f5920

extern "C" void* __stdcall GetProcessHeap();
extern "C" int __stdcall HeapFree(void* hHeap, unsigned long dwFlags, void* lpMem);

struct CXTPControl {
    void* vtable;
    void* m_pad;
    void* m_pUnknown;
    void* m_pData;
    void Destruct();
};

void CXTPControl::Destruct()
{
    void* p = m_pUnknown;
    vtable = (void*)0x9f1760;
    if (p != 0) {
        void** vt = *(void***)p;
        void (*fn)(void*) = (void (*)(void*))vt[2];
        fn(p);
    }
    if (m_pData != 0) {
        void* h = GetProcessHeap();
        if (h != 0) {
            HeapFree(h, 0, m_pData);
        }
    }
}

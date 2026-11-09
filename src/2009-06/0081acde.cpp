// from server: 100% by tester
struct CXTIconHandle {
    void* m_vtable;
    void* m_ptr;
    char m_flag;
    void Destroy();
};

extern "C" void (__stdcall *HeapDestroy)(void*);

void CXTIconHandle::Destroy()
{
    m_vtable = (void*)0x7e50d0;
    if (m_flag != 0) {
        void* p = m_ptr;
        if (p != 0) {
            HeapDestroy(p);
        }
    }
}

// from server: 61% by colin
struct CXTIconHandle {
    void* m_p;
    unsigned int GetSize(unsigned int flags);
};

extern "C" unsigned long __stdcall HeapSize(void* heap, unsigned long flags, const void* mem);

unsigned int CXTIconHandle::GetSize(unsigned int flags)
{
    return HeapSize(0, flags, m_p);
}

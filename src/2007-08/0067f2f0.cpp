// from server: 100% by colin
struct CXTPControlSelector {
    int m_nUnknown0;
    void* m_pUnknown4;
    void* m_pUnknown8;
    void Set(void* p);
};

void CXTPControlSelector::Set(void* p)
{
    if (m_pUnknown4 != 0 && p != 0) {
        void* result = ((void* (__thiscall*)(void*, void*))((*(void***)m_pUnknown4)[0x30 / 4]))(m_pUnknown4, p);
        if (m_pUnknown8 == 0 && result != 0) {
            m_pUnknown8 = result;
        }
    }
}

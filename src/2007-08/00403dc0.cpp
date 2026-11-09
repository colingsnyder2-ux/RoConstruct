// from server: 100% by tajop
struct IUnk {
    virtual long __stdcall QueryInterface(const void* riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct CComObjectConnPt {
    IUnk** m_aT;
    int m_nSize;
    virtual long __stdcall Unadvise(unsigned long dwCookie);
    IUnk* GetAt(int nIndex);
    IUnk* GetUnknown(unsigned long dwCookie);
    int Remove(unsigned long dwCookie);
};

inline IUnk* CComObjectConnPt::GetAt(int nIndex)
{
    if (nIndex < 0 || nIndex >= m_nSize)
        return 0;
    return m_aT[nIndex];
}

inline IUnk* CComObjectConnPt::GetUnknown(unsigned long dwCookie)
{
    if (dwCookie == 0 || dwCookie > (unsigned long)m_nSize)
        return 0;
    return GetAt((int)dwCookie - 1);
}

inline int CComObjectConnPt::Remove(unsigned long dwCookie)
{
    unsigned long idx = dwCookie - 1;
    if (idx < dwCookie && idx < (unsigned long)m_nSize) {
        IUnk** p = &m_aT[idx];
        if (*p != 0) {
            *p = 0;
            return 1;
        }
    }
    return 0;
}

long __stdcall CComObjectConnPt::Unadvise(unsigned long dwCookie)
{
    IUnk* p = GetUnknown(dwCookie);
    long hr = Remove(dwCookie) ? 0 : (long)0x80040200;
    if (hr == 0 && p != 0)
        p->Release();
    return hr;
}

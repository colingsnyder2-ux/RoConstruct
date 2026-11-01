// from server: 100% by coldek
// from server: 100% by EspClaude
// roc 2008-06 0040f570  unit: VCBrowserViewExternal::?$CComObject  size: 103 bytes

struct IUnknown {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct CException {
    void Delete();
};

__declspec(noreturn) void __stdcall AtlThrow(long);

struct CopyInterface {
    static long copy(IUnknown** p1, IUnknown** p2)
    {
        int cond = !!(p1 != 0 && p2 != 0);
        if (!cond)
            AtlThrow((long)0x80004005);
        *p1 = *p2;
        if (*p1)
            (*p1)->AddRef();
        return 0;
    }
};

struct CComPtrUnk {
    IUnknown* p;
    IUnknown* operator=(IUnknown* lp)
    {
        if (p != lp) {
            if (lp)
                lp->AddRef();
            if (p)
                p->Release();
            p = lp;
        }
        return p;
    }
};

typedef IUnknown* Entry;

struct S {
    void* vtable;
    CComPtrUnk m_spUnk;
    Entry* m_begin;
    Entry* m_end;
    Entry* m_iter;
    unsigned long m_dwFlags;

    long Init(Entry* begin, Entry* end, IUnknown* pUnk, unsigned long flags);
};

long S::Init(Entry* begin, Entry* end, IUnknown* pUnk, unsigned long flags)
{
    if (flags == 3) {
        try {
            m_begin = new Entry[end - begin];
        }
        catch (CException* e) {
            e->Delete();
        }
        m_iter = m_begin;
        if (m_begin == 0)
            return (long)0x8007000E;
        for (Entry* i = begin; i != end; i++) {
            long hr = CopyInterface::copy(m_iter, i);
            if (hr < 0)
                return hr;
            m_iter++;
        }
        m_end = m_begin + (end - begin);
    } else {
        m_begin = begin;
        m_end = end;
    }
    m_spUnk = pUnk;
    m_iter = m_begin;
    m_dwFlags = flags;
    return 0;
}

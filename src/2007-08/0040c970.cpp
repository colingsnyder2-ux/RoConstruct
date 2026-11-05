// from server: 42% by colin
struct IBrowserViewExternal {
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct CComObjectNoLock {
    long __stdcall CreateInstance(IBrowserViewExternal** ppv);
};

extern "C" {
    int __stdcall CoCreateInstance(const void* rclsid, void* pUnkOuter, unsigned long dwClsContext, const void* riid, void** ppv);
}

struct CComPtr {
    IBrowserViewExternal* p;
    void Release();
    void AddRef();
};

struct CComBSTR {
    unsigned short* m_str;
    CComBSTR();
    ~CComBSTR();
    void Attach(unsigned short* p);
    unsigned short* Detach();
};

struct CComVariant {
    unsigned short vt;
    void Clear();
};

extern "C" int __stdcall StringCchPrintfW(unsigned short* pszDest, unsigned int cchDest, const unsigned short* pszFormat, ...);

long __stdcall CComObjectNoLock::CreateInstance(IBrowserViewExternal** ppv)
{
    CComPtr spView;
    CComBSTR bstr;
    CComVariant var;
    IBrowserViewExternal* pView = 0;
    long hr = 0;

    hr = CoCreateInstance((const void*)0x78523c, 0, 0x17, (const void*)0x790290, (void**)&pView);
    if (hr == 0)
    {
        bstr.Attach((unsigned short*)0x786408);
        StringCchPrintfW((unsigned short*)0x7902d0, 0x100, (const unsigned short*)0x7902d0, pView);
        bstr.Detach();
        var.Clear();
        spView.p = pView;
        if (ppv)
        {
            *ppv = spView.p;
            if (spView.p)
                spView.AddRef();
        }
        else
        {
            hr = 0x80004003;
        }
        if (spView.p)
            spView.Release();
    }
    else
    {
        if (pView)
            pView->Release();
        if (ppv)
            *ppv = 0;
        hr = 0x80004003;
    }
    return hr;
}

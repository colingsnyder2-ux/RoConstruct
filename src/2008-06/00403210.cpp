// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 00403210  unit: CSiteLock<CLauncher>::GetOurUrl  size: 420 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403210
//
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

typedef unsigned long DWORD;
typedef unsigned long ULONG;
typedef long HRESULT;
typedef wchar_t OLECHAR;
struct GUID { unsigned long a; unsigned short b, c; unsigned char d[8]; };
#define FAILED(hr) ((HRESULT)(hr) < 0)
#define S_OK 0

extern "C" const GUID IID_IServiceProvider;
extern "C" const GUID IID_IWebBrowser2;
extern "C" const GUID IID_IInternetSecurityManager;
extern "C" const GUID SID_SWebBrowserApp;
extern "C" const GUID SID_SInternetSecurityManager;

struct IUnknown {
    virtual HRESULT __stdcall QueryInterface(const GUID&, void**) = 0;
    virtual ULONG __stdcall AddRef() = 0;
    virtual ULONG __stdcall Release() = 0;
};

struct IServiceProvider : IUnknown {
    virtual HRESULT __stdcall QueryService(const GUID&, const GUID&, void**) = 0;
};

struct IWebBrowser2 : IUnknown {
    virtual void __stdcall s3() = 0; virtual void __stdcall s4() = 0; virtual void __stdcall s5() = 0;
    virtual void __stdcall s6() = 0; virtual void __stdcall s7() = 0; virtual void __stdcall s8() = 0;
    virtual void __stdcall s9() = 0; virtual void __stdcall s10() = 0; virtual void __stdcall s11() = 0;
    virtual void __stdcall s12() = 0; virtual void __stdcall s13() = 0; virtual void __stdcall s14() = 0;
    virtual void __stdcall s15() = 0; virtual void __stdcall s16() = 0; virtual void __stdcall s17() = 0;
    virtual void __stdcall s18() = 0; virtual void __stdcall s19() = 0; virtual void __stdcall s20() = 0;
    virtual void __stdcall s21() = 0; virtual void __stdcall s22() = 0; virtual void __stdcall s23() = 0;
    virtual void __stdcall s24() = 0; virtual void __stdcall s25() = 0; virtual void __stdcall s26() = 0;
    virtual void __stdcall s27() = 0; virtual void __stdcall s28() = 0; virtual void __stdcall s29() = 0;
    virtual HRESULT __stdcall get_LocationURL(OLECHAR**) = 0;
};

struct IInternetSecurityManager : IUnknown {
    virtual void __stdcall s3() = 0;
    virtual void __stdcall s4() = 0;
    virtual HRESULT __stdcall MapUrlToZone(const OLECHAR*, DWORD*, DWORD) = 0;
};

struct IObjectWithSite : IUnknown {
    virtual HRESULT __stdcall SetSite(IUnknown*) = 0;
    virtual HRESULT __stdcall GetSite(const GUID&, void**) = 0;
};

struct CComBSTR {
    OLECHAR* m_str;
    OLECHAR** operator&() { return &m_str; }
    operator OLECHAR*() const { return m_str; }
};

template <class T>
struct CComPtr {
    T* p;
    CComPtr() : p(0) {}
    ~CComPtr() { if (p) p->Release(); }
    T* operator->() const { return p; }
    T** operator&() { return &p; }
};

template <class T>
class CSiteLock {
public:
    virtual void lock0();
    void* reserved;
    HRESULT GetOurUrl(CComBSTR& bstrURL, DWORD& dwZone)
    {
        HRESULT hr = S_OK;
        CComPtr<IServiceProvider> spSrvProv;

        T* pT = static_cast<T*>(this);
        hr = pT->GetSite(IID_IServiceProvider, (void**)&spSrvProv);
        if (FAILED(hr))
            return hr;

        CComPtr<IWebBrowser2> spWebBrowser;
        hr = spSrvProv->QueryService(SID_SWebBrowserApp, IID_IWebBrowser2, (void**)&spWebBrowser);
        if (FAILED(hr))
            return hr;

        if (FAILED(spWebBrowser->get_LocationURL(&bstrURL)))
            return hr;

        CComPtr<IInternetSecurityManager> spInetSecMgr;
        hr = spSrvProv->QueryService(SID_SInternetSecurityManager, IID_IInternetSecurityManager, (void**)&spInetSecMgr);
        if (FAILED(hr))
            return hr;

        hr = spInetSecMgr->MapUrlToZone(bstrURL, &dwZone, 0);
        if (FAILED(hr))
            return hr;
        return S_OK;
    }
};

struct Root {
    virtual void root0();
    long m_dwRef;
};

class CLauncher : public Root, public CSiteLock<CLauncher>, public IObjectWithSite {
public:
    HRESULT __stdcall QueryInterface(const GUID&, void**);
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall SetSite(IUnknown*);
    HRESULT __stdcall GetSite(const GUID&, void**);
};

template class CSiteLock<CLauncher>;

// from server: 100% by EspClaude
// roc 2008-06 0042a930
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef long HRESULT;
#define S_OK ((HRESULT)0L)
struct GUID { unsigned long a; unsigned short b, c; unsigned char d[8]; };
extern "C" const GUID IID_IUnknown;
extern "C" const GUID IID_IObjectIdentity;
struct IUnknown {
    virtual long __stdcall QueryInterface(const GUID &, void **) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct IObjectIdentity : IUnknown {
    virtual long __stdcall IsEqualObject(IUnknown *) = 0;
};
template <class T> class CComPtr {
public:
    T *p;
    CComPtr() throw() { p = 0; }
    ~CComPtr() throw() { if (p) p->Release(); }
    T **operator&() throw() { return &p; }
    T *operator->() const throw() { return p; }
    operator T *() const throw() { return p; }
};

bool equalObjects(IUnknown *first, IUnknown *second)
{
    CComPtr<IUnknown> a;
    CComPtr<IUnknown> b;
    CComPtr<IObjectIdentity> identity;
    if (first == second) return true;
    if (first && second) {
        first->QueryInterface(IID_IUnknown, (void **)&a);
        second->QueryInterface(IID_IUnknown, (void **)&b);
        if (a == b) return true;
        if (a && b) {
            HRESULT hr = a->QueryInterface(IID_IObjectIdentity, (void **)&identity);
            if (hr >= S_OK && identity) {
                hr = identity->IsEqualObject(b);
                if (hr == S_OK) return true;
            }
        }
    }
    return false;
}

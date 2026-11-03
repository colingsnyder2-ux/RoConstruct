// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct _GUID;
struct IUnknownX {
    virtual long __stdcall QueryInterface(const _GUID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct IObjectWithSiteX : IUnknownX {
    virtual long __stdcall SetSite(IUnknownX* p) = 0;
    virtual long __stdcall GetSite(const _GUID& riid, void** ppv) = 0;
};
template <class T> struct CComPtrX {
    T* p;
    operator T*() const { return p; }
    T* operator->() const { return p; }
};
template <class T>
class IObjectWithSiteImplX : public IObjectWithSiteX {
public:
    long __stdcall GetSite(const _GUID& riid, void** ppvSite);
};
template <class T>
long __stdcall IObjectWithSiteImplX<T>::GetSite(const _GUID& riid, void** ppvSite)
{
    T* pT = static_cast<T*>(this);
    long hRes = 0x80004003L;
    if (ppvSite != 0) {
        if (pT->m_spUnkSite)
            hRes = pT->m_spUnkSite->QueryInterface(riid, ppvSite);
        else {
            *ppvSite = 0;
            hRes = 0x80004005L;
        }
    }
    return hRes;
}
struct PadBase { virtual void f0(); char pad[0x1c]; };
class CWorkspaceX : public PadBase, public IObjectWithSiteImplX<CWorkspaceX> {
public:
    CComPtrX<IUnknownX> m_spUnkSite;
};
template class IObjectWithSiteImplX<CWorkspaceX>;

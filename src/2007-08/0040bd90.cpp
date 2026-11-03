// from server: 93% by EspClaude
// roc 2007-08 0040bd90  unit: CBrowserView
typedef long HRESULT;
typedef short VARIANT_BOOL;
struct IDispatchLike {
    virtual HRESULT __stdcall QueryInterface(const void* riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
template<class T> class CComPtrLike {
public:
    T* p;
    T* operator=(T* lp)
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
    bool operator!() const { return p == 0; }
    HRESULT CopyTo(T** ppT)
    {
        if (ppT == 0)
            return 0x80004003L;
        *ppT = p;
        if (p)
            p->AddRef();
        return 0;
    }
};
class CBrowserViewExternal {
public:
    char pad[0x14];
    IDispatchLike* dispPart() { return reinterpret_cast<IDispatchLike*>(pad + 0x14); }
};
struct CExternalObject {
    char pad[0x14];
    char disp[8];
    VARIANT_BOOL m_isIDE;
    IDispatchLike* getDispatch() { return reinterpret_cast<IDispatchLike*>(disp); }
    static HRESULT __cdecl CreateInstance(CExternalObject** pp, void* outer);
};
class CBrowserView {
public:
    virtual ~CBrowserView();
    char pad[0x2ac];
    CComPtrLike<IDispatchLike> m_external;
    HRESULT GetExternal(IDispatchLike** ppDispatch);
};
class CIDEBrowserView : public CBrowserView {
};
HRESULT CBrowserView::GetExternal(IDispatchLike** ppDispatch)
{
    if (!m_external) {
        CExternalObject* pObj;
        HRESULT hr = CExternalObject::CreateInstance(&pObj, 0);
        if (hr)
            return hr;
        CIDEBrowserView* pIDE = dynamic_cast<CIDEBrowserView*>(this);
        IDispatchLike* pDisp = pObj->getDispatch();
        pObj->m_isIDE = pIDE ? -1 : 0;
        m_external = pDisp;
    }
    return m_external.CopyTo(ppDispatch);
}

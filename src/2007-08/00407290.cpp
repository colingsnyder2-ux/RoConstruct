// from server: 90% by EspClaude
// roc 2007-08 00407290  unit: UIEnumConnections::V?$CComEnum::?$CComObject  size: 257 bytes
// ATL 8.0 CComEnumImpl<IEnumConnections, &IID_IEnumConnections, CONNECTDATA, _Copy<CONNECTDATA> >::Clone,
// rewritten from the target bytes: layout vtbl+0, m_spUnk +4, m_begin +8, m_end +0xc, m_iter +0x10,
// m_dwFlags +0x14 (BitOwn = 2); CComObject<CComEnum>::CreateInstance 0x406120 (stdcall),
// Init 0x404400 (thiscall, flags 0), AtlInternalQueryInterface 0x4022a0 (entries 0x784e28, iid 0x784e40),
// delete p = scalar deleting dtor at vtbl +0x1c.
typedef long HRESULT;
typedef unsigned long DWORD;
struct _GUID;
typedef const _GUID& REFIID;

struct IUnknown
{
    virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct CONNECTDATA { IUnknown* pUnk; DWORD dwCookie; };

struct IEnumConnections : public IUnknown
{
    virtual HRESULT __stdcall Next(unsigned long cConnections, CONNECTDATA* rgcd, unsigned long* pcFetched) = 0;
    virtual HRESULT __stdcall Skip(unsigned long cConnections) = 0;
    virtual HRESULT __stdcall Reset() = 0;
    virtual HRESULT __stdcall Clone(IEnumConnections** ppEnum) = 0;
};

template <class T>
class CComPtr
{
public:
    CComPtr() throw() { p = 0; }
    CComPtr(T* lp) throw() { p = lp; if (p != 0) p->AddRef(); }
    ~CComPtr() throw() { if (p) p->Release(); }
    operator T*() const throw() { return p; }
    T* p;
};

struct _ATL_INTMAP_ENTRY;
extern "C" HRESULT __stdcall AtlInternalQueryInterface(void* pThis, const _ATL_INTMAP_ENTRY* pEntries, REFIID iid, void** ppvObject);
extern const _GUID IID_IEnumConnections;

enum CComEnumFlags { AtlFlagNoCopy = 0, AtlFlagTakeOwnership = 2, AtlFlagCopy = 3 };

class CComEnumConnectionsImpl : public IEnumConnections
{
public:
    HRESULT __stdcall Next(unsigned long celt, CONNECTDATA* rgelt, unsigned long* pceltFetched);
    HRESULT __stdcall Skip(unsigned long celt);
    HRESULT __stdcall Reset() { m_iter = m_begin; return 0; }
    HRESULT __stdcall Clone(IEnumConnections** ppEnum);
    HRESULT Init(CONNECTDATA* begin, CONNECTDATA* end, IUnknown* pUnk, CComEnumFlags flags = AtlFlagNoCopy);
    enum FlagBits { BitCopy = 1, BitOwn = 2 };

    CComPtr<IUnknown> m_spUnk;
    CONNECTDATA* m_begin;
    CONNECTDATA* m_end;
    CONNECTDATA* m_iter;
    DWORD m_dwFlags;
};

class CComObject_CComEnumConnections : public CComEnumConnectionsImpl
{
public:
    virtual ~CComObject_CComEnumConnections();
    static const _ATL_INTMAP_ENTRY* __stdcall _GetEntries() throw() { return _entries; }
    HRESULT _InternalQueryInterface(REFIID iid, void** ppvObject) throw()
    {
        return AtlInternalQueryInterface(this, _GetEntries(), iid, ppvObject);
    }
    static HRESULT __stdcall CreateInstance(CComObject_CComEnumConnections** pp);
    static const _ATL_INTMAP_ENTRY _entries[];
};

HRESULT __stdcall CComEnumConnectionsImpl::Clone(IEnumConnections** ppEnum)
{
    typedef CComObject_CComEnumConnections _class;
    HRESULT hRes = (HRESULT)0x80004003;
    if (ppEnum != 0)
    {
        *ppEnum = 0;
        _class* p;
        hRes = _class::CreateInstance(&p);
        if (hRes >= 0)
        {
            // If this object has ownership of the data then we need to keep it around
            _class* pObj = p;
            hRes = pObj->Init(m_begin, m_end, (m_dwFlags & BitOwn) ? this : m_spUnk);
            if (hRes >= 0)
            {
                pObj->m_iter = m_iter;
                hRes = pObj->_InternalQueryInterface(IID_IEnumConnections, (void**)ppEnum);
            }
            if (hRes < 0)
                delete pObj;
        }
    }
    return hRes;
}

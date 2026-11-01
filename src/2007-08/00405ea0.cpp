// from server: 100% by colin
// roc 2007-08 00405ea0  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00405ea0
//
// 00405ea0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00405ea4  834118ff             add dword ptr [ecx + 0x18], -1
// 00405ea8  56                   push esi
// 00405ea9  8b7118               mov esi, dword ptr [ecx + 0x18]
// 00405eac  750d                 jne 0x405ebb
// 00405eae  85c9                 test ecx, ecx
// 00405eb0  7409                 je 0x405ebb
// 00405eb2  8b01                 mov eax, dword ptr [ecx]
// 00405eb4  8b501c               mov edx, dword ptr [eax + 0x1c]
// 00405eb7  6a01                 push 1
// 00405eb9  ffd2                 call edx
// 00405ebb  8bc6                 mov eax, esi
// 00405ebd  5e                   pop esi
// 00405ebe  c20400               ret 4
// copied from an identical function in another client (function ?Release@?$CComObject@VCComEnumConnectionPoints@ATL@@@ATL@@UAGKXZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct GUID;

struct IUnknown
{
    virtual long __stdcall QueryInterface(const GUID& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct IConnectionPoint;

struct IEnumConnectionPoints : public IUnknown
{
    virtual long __stdcall Next(unsigned long cConnections, IConnectionPoint** ppCP, unsigned long* pcFetched) = 0;
    virtual long __stdcall Skip(unsigned long cConnections) = 0;
    virtual long __stdcall Reset() = 0;
    virtual long __stdcall Clone(IEnumConnectionPoints** ppEnum) = 0;
};

namespace ATL {
class CComSingleThreadModel
{
public:
    static unsigned long Increment(long* p) throw() { return ++(*p); }
    static unsigned long Decrement(long* p) throw() { return --(*p); }
};

class CComObjectRootBase
{
public:
    long m_dwRef;
};

template<class ThreadModel>
class CComObjectRootEx : public CComObjectRootBase
{
public:
    unsigned long InternalRelease()
    {
        return ThreadModel::Decrement(&m_dwRef);
    }
};

class CComEnumImpl : public IEnumConnectionPoints
{
public:
    IConnectionPoint** m_begin;
    IConnectionPoint** m_end;
    IConnectionPoint** m_iter;
    unsigned long m_dwFlags;
    IUnknown* m_spUnk;
};

class CComEnumConnectionPoints : public CComEnumImpl, public CComObjectRootEx<CComSingleThreadModel>
{
};

template<class Base>
class CComObject : public Base
{
public:
    virtual ~CComObject();
    virtual unsigned long __stdcall Release()
    {
        unsigned long l = this->InternalRelease();
        if (l == 0)
            delete this;
        return l;
    }
};

template class CComObject<CComEnumConnectionPoints>;
}
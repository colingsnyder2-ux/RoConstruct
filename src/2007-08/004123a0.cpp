// from server: 100% by colin
// roc 2007-08 004123a0  unit: VCContent::?$CComObject  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004123a0
//
// 004123a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004123a4  834108ff             add dword ptr [ecx + 8], -1
// 004123a8  56                   push esi
// 004123a9  8b7108               mov esi, dword ptr [ecx + 8]
// 004123ac  750d                 jne 0x4123bb
// 004123ae  85c9                 test ecx, ecx
// 004123b0  7409                 je 0x4123bb
// 004123b2  8b01                 mov eax, dword ptr [ecx]
// 004123b4  8b5010               mov edx, dword ptr [eax + 0x10]
// 004123b7  6a01                 push 1
// 004123b9  ffd2                 call edx
// 004123bb  8bc6                 mov eax, esi
// 004123bd  5e                   pop esi
// 004123be  c20400               ret 4
// copied from an identical function in another client (function ?Release@?$CComObject@VCContent@ATL@ns_ROCX000007@@@ATL@ns_ROCX000007@@UAGKXZ)

namespace ns_ROCX000007 {
struct GUID;

struct IUnknown
{
    virtual long __stdcall QueryInterface(const GUID& riid, void** ppvObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct IServiceProvider : public IUnknown
{
    virtual long __stdcall QueryService(const GUID& guidService, const GUID& riid, void** ppvObject) = 0;
};

struct IContentSink : public IUnknown
{
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

class CContent : public IServiceProvider, public IContentSink, public CComObjectRootEx<CComSingleThreadModel>
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

template class CComObject<CContent>;
}
}

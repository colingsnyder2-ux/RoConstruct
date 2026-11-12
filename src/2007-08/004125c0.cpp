// from server: 91% by EspClaude
// roc 2007-08 004125c0  unit: VCContent::?$CComObject  size: 213 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
//
// ATL CComCreator<CComObject<T>>::CreateInstance shape: ATLTRY(new) with an MFC
// catch(CException*) funclet (0x412695, call 0x62ff2c = CException::Delete),
// new size 0x94, std::stringstream member at +0xc (msvcp80 ctor(3, 1)),
// two interface vptrs at +0/+4, m_dwRef at +8, _pAtlModule->Lock() (vslot 1),
// QueryInterface (vslot 0, stdcall), virtual scalar deleting dtor at vslot 4.

#include <sstream>

struct GUID { unsigned long d1; unsigned short d2, d3; unsigned char d4[8]; };

struct CException {
    void Delete();
};

struct AtlModule {
    virtual void v0();
    virtual long Lock();
};
extern AtlModule* _pAtlModule;   // 0x8bae44

struct __declspec(novtable) IContent {
    virtual long __stdcall QueryInterface(const GUID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
    virtual long __stdcall Method3() = 0;
};

struct __declspec(novtable) IOther {
    virtual long __stdcall QueryInterface(const GUID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct RootBase {
    long m_dwRef;
    RootBase() : m_dwRef(0) {}
    long InternalAddRef() { return ++m_dwRef; }
    long InternalRelease() { return --m_dwRef; }
    void SetVoid(void*) {}
    void InternalFinalConstructAddRef() { InternalAddRef(); }
    void InternalFinalConstructRelease() { InternalRelease(); }
    long _AtlInitialConstruct() { return 0; }
    long FinalConstruct() { return 0; }
    long _AtlFinalConstruct() { return 0; }
};

class __declspec(novtable) Content : public IContent, public IOther, public RootBase {
public:
    std::stringstream m_stream;
};

template <class Base>
class ComObject : public Base {
public:
    __forceinline ComObject(void* = 0) throw() { _pAtlModule->Lock(); }
    virtual ~ComObject();
    long __stdcall QueryInterface(const GUID& riid, void** ppv);
    unsigned long __stdcall AddRef();
    unsigned long __stdcall Release();
    long __stdcall Method3();
};

template <class T1>
struct ComCreator {
    static long __stdcall CreateInstance(void* pv, const GUID& riid, void** ppv)
    {
        if (ppv == 0)
            return 0x80004003L;
        *ppv = 0;
        long hRes = 0x8007000EL;
        T1* p = 0;
        try {
            p = new T1(pv);
        } catch (CException* e) {
            e->Delete();
        }
        if (p != 0) {
            p->SetVoid(pv);
            p->InternalFinalConstructAddRef();
            hRes = p->_AtlInitialConstruct();
            if (hRes >= 0)
                hRes = p->FinalConstruct();
            if (hRes >= 0)
                hRes = p->_AtlFinalConstruct();
            p->InternalFinalConstructRelease();
            if (hRes == 0)
                hRes = p->QueryInterface(riid, ppv);
            if (hRes != 0)
                delete p;
        }
        return hRes;
    }
};

template struct ComCreator<ComObject<Content> >;

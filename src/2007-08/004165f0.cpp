// from server: 70% by EspClaude
// from server: 53% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_af2fc63731fc5292.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog of ATL 8 CComCreator<T1>::CreateInstance (atlcom.h), for the 2007-08
// VCLuaFunction aggregate object.  Read off the target bytes: new size 0x40, out-of-line
// T1(void*) ctor (00415f50, ret 4), QueryInterface at vtable slot 0 (stdcall), scalar
// deleting destructor at vtable slot +0xc, MFC ATLTRY catch, E_POINTER 0x80004003, E_OUTOFMEMORY 0x8007000e.
struct _GUID { unsigned long Data1; unsigned short Data2; unsigned short Data3; unsigned char Data4[8]; };

struct T1 {
    virtual long __stdcall QueryInterface(const _GUID& iid, void** ppvObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual ~T1();
    T1(void* pv);
    char m_rest[0x40 - 4];
};

// MFC ATLTRY: catch (CException* e) { e->Delete(); } -- catch object at [ebp-0x18],
// CException::Delete called through the MFC80 import thunk 0062ff2c.
class CException {
public:
    void Delete();
};

struct CComCreator_T1 {
    static long __stdcall CreateInstance(void* pv, const _GUID& riid, void** ppv);
};

long __stdcall CComCreator_T1::CreateInstance(void* pv, const _GUID& riid, void** ppv)
{
    if (ppv == 0)
        return 0x80004003L;
    *ppv = 0;

    long hRes = 0x8007000EL;
    T1* p = 0;
    try { p = new T1(pv); } catch (CException* e) { e->Delete(); }
    if (p != 0)
    {
        hRes = p->QueryInterface(riid, ppv);
        if (hRes != 0)
            delete p;
    }
    return hRes;
}

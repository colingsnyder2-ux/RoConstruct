// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
struct Module { virtual long Unlock(); virtual long Lock(); };
extern Module* _pAtlModule;

struct Root { long m_dwRef; Root() : m_dwRef(0) {} };
struct __declspec(novtable) I0 { virtual long __stdcall a0() = 0; };
struct __declspec(novtable) I4 { virtual long __stdcall a4() = 0; };
struct B8 { void* c; void* d; B8() { d = 0; c = 0; } };
struct X8 : B8 { virtual long __stdcall a8(); };
struct __declspec(novtable) I14 { virtual long __stdcall a14() = 0; };

class __declspec(novtable) T : public Root, public I0, public I4, public X8, public I14 {
public:
    short flag;
    T() : flag(0) {}
};

template<class Base> class CComObject : public Base {
public:
    CComObject(void* = 0) { _pAtlModule->Lock(); }
    virtual ~CComObject();
    long __stdcall a0();
    long __stdcall a4();
    long __stdcall a8();
    long __stdcall a14();
};
template class CComObject<T>;

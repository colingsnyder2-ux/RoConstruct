// from server: 71% by EspClaude
// from server: 57% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_7e8adf530f0657ff.cpp

// Candidate translation unit (score above; library headers required).
// 0040a380 (app ATL code, not Boost.Thread): an ATL CComAggObject<T>(void* pv)-shaped
// constructor. Layout read from the target's stores: +0 own IUnknown vtable, +4 m_dwRef = 0,
// m_contained at +8 with polymorphic subobjects at +8, +0xc, +0x10 (base ctor writes a vtable,
// zeroes +0x14/+0x18), +0x1c (base ctor writes a vtable, zeroes +0x20), +0x24 (no vtable
// write, zeroes +0x28), +0x2c, and the contained object's root (m_pOuterUnknown = pv) at +0x30;
// then the global module pointer's virtual slot +4 (Lock) is called.
#ifndef NDEBUG
#define NDEBUG
#endif
#ifndef _DLL
#define _DLL
#endif

struct Module { virtual ~Module(); virtual long Lock(); };
extern Module* g_pModule;

struct __declspec(novtable) IUnk { virtual long __stdcall QueryInterface(const void*, void**) = 0; };
struct RootBase {
    RootBase() : m_dwRef(0) {}
    union { long m_dwRef; void* m_pOuterUnknown; };
};

struct __declspec(novtable) IA { virtual long __stdcall a() = 0; };
struct __declspec(novtable) IB { virtual long __stdcall b() = 0; };
struct C1Data { C1Data() { m2 = 0; m1 = 0; } void* m1; void* m2; };
struct C1 : public C1Data { virtual long __stdcall c1(); };
struct C2 { C2() : m(0) {} virtual long __stdcall c2(); void* m; };
struct __declspec(novtable) C3 { C3() : p(0) {} virtual long __stdcall c3(); void* p; };
struct __declspec(novtable) ID { virtual long __stdcall d() = 0; };

class __declspec(novtable) Contained : public IA, public IB, public C1, public C2, public C3, public ID, public RootBase {
public:
    ~Contained();
};

class ContainedObject : public Contained {
public:
    ContainedObject(void* pv) { m_pOuterUnknown = pv; }
    long __stdcall a();
    long __stdcall b();
    long __stdcall c1();
    long __stdcall c2();
    long __stdcall c3();
    long __stdcall d();
};

class AggObject : public IUnk, public RootBase {
public:
    AggObject(void* pv);
    long __stdcall QueryInterface(const void*, void**);
    ContainedObject m_contained;
};

AggObject::AggObject(void* pv) : m_contained(pv)
{
    g_pModule->Lock();
}

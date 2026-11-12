// from server: 100% by EspClaude
// from server: 40% by colin
// roc 2007-08 00437f80  unit: CStandardOutputView  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00437f80
//
// Shape: CComQIPtr ctor, CComPtr dtors, CComVariant(short) passed by value as VARIANT,
// member queue at +0xf4 (push_back 0x437a40, front 0x499f10, pop_front 0x437570, size at +0x104).
struct GUID_ { unsigned long d1; unsigned short d2, d3; unsigned char d4[8]; };
extern const GUID_ IID_target;   // 0x78cd80

struct VARIANT_ {
    unsigned short vt;
    unsigned short r1, r2, r3;
    union { short iVal; long lVal; };
    long r4;
};
extern "C" __declspec(dllimport) long __stdcall VariantClear(VARIANT_* pvarg);

struct IUnk {
    virtual long __stdcall QueryInterface(const GUID_& iid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

#define D(n) virtual void __stdcall d##n() = 0;
struct IElem : IUnk {
    D(3) D(4) D(5) D(6) D(7) D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31) D(32) D(33) D(34) D(35)
    D(36) D(37) D(38) D(39) D(40) D(41) D(42) D(43) D(44) D(45)
    virtual long __stdcall m46(VARIANT_ v) = 0;   // vtbl +0xb8
};
struct IDoc : IUnk {
    D(3) D(4) D(5) D(6) D(7) D(8) D(9) D(10) D(11) D(12)
    virtual long __stdcall m13(IUnk* a, IUnk** out) = 0;  // +0x34
    D(14) D(15) D(16) D(17) D(18)
    virtual long __stdcall m19(IUnk* a, IUnk** out) = 0;  // +0x4c
};

template <class T> struct CComPtr {
    T* p;
    CComPtr() throw() : p(0) {}
    ~CComPtr() throw() { if (p) p->Release(); }
};
template <class T> struct CComQIPtr : CComPtr<T> {
    CComQIPtr(IUnk* lp) throw() { if (lp != 0) lp->QueryInterface(IID_target, (void**)&this->p); }
};

struct CComVariant : VARIANT_ {
    CComVariant(short n) { vt = 2; iVal = n; }
    ~CComVariant() { VariantClear(this); }
};

struct Queue {
    char pad[0x10];
    unsigned int size;           // this+0x104
    void push_back(const CComQIPtr<IUnk>& v);
    CComPtr<IUnk>& front();
    void pop_front();
};

struct CStandardOutputView {
    char pad[0xf4];
    Queue queue;                 // +0xf4
    char pad2[0x10c - 0x108];
    IDoc* doc;                   // +0x10c
    void func_00437f80(IElem* elem);
};

void CStandardOutputView::func_00437f80(IElem* elem)
{
    CComQIPtr<IUnk> sp(elem);
    CComPtr<IUnk> out;
    if (doc->m19(sp.p, &out.p) == 0) {
        elem->m46(CComVariant(0));
        queue.push_back(sp);
        if (queue.size > 400) {
            CComPtr<IUnk> old;
            IDoc* d = doc;
            IUnk* f = queue.front().p;
            d->m13(f, &old.p);
            queue.pop_front();
        }
    }
}

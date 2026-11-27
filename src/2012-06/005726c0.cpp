// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
struct Cnt {
    virtual ~Cnt(); virtual void dispose(); virtual void destroy();
    long use; long weak;
    void weak_release() { if (_InterlockedDecrement(&weak) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use) == 0) { dispose(); weak_release(); } }
};
struct SP {
    void* px; Cnt* pn;
    ~SP() { if (pn) pn->release(); }
};
#pragma pack(push, 1)
struct A0 { char a[5]; };
struct Q { int q; };
struct T : A0, Q {};
#pragma pack(pop)
void intrusive_ptr_release(Q* q);
struct M {
    T* p;
    ~M() { if (p) intrusive_ptr_release(p); }
};
struct St { SP a; M b; ~St(); };
St::~St() {}

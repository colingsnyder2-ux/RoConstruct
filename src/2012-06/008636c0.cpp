// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
struct CB {
    virtual ~CB();
    virtual void dispose();
    virtual void destroy();
    volatile long use; volatile long weak;
    void weak_release() { if (_InterlockedDecrement(&weak) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use) == 0) { dispose(); weak_release(); } }
};
struct T { __declspec(dllimport) void m(); };
struct SP {
    T* px; CB* pn;
    ~SP() { if (pn) pn->release(); }
};
void f(SP sp) { sp.px->m(); }
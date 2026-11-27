// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
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
struct SP { void* px; CB* pn; ~SP() { if (pn) pn->release(); } };
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { char b[28]; ~String() { destroyString(this); } };
struct Base { __declspec(dllimport) virtual ~Base(); char pad[8]; };
struct M2 : Base { String s1; virtual ~M2() {} };
struct M1 : M2 { char pad[0x30 - 0x28]; String s2; virtual ~M1() {} };
struct CRobloxDoc : M1 { SP sp; virtual ~CRobloxDoc(); };
CRobloxDoc::~CRobloxDoc() {}
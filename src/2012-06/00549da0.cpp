// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) destroy();
        }
    }
    void add_ref() { _InterlockedIncrement(&use_count_); }
};

struct shared_count {
    sp_counted_base* pi;
    shared_count() : pi(0) {}
    shared_count(const shared_count& r) : pi(r.pi) { if (pi) pi->add_ref(); }
    ~shared_count() { if (pi) pi->release(); }
};

struct Base1 { int pad; };
struct Other { char a[0x18]; };
struct Derived : Other, Base1 { int x; };
struct Creator : Derived {};

struct sp_Derived {
    Derived* px;
    shared_count pn;
};
struct sp_Base {
    Base1* px;
    shared_count pn;
    sp_Base(const sp_Derived& r) : px(r.px), pn(r.pn) {}
};

extern "C" void __cdecl sub_972290(unsigned char, const char*);
sp_Derived __cdecl sub_4141e0();
extern unsigned char byte_E580B3;
extern int dword_E1653C;
extern char (__cdecl *dword_E5809C)(const char*, const char*, int);

sp_Base __stdcall sub_4148C0()
{
    if (byte_E580B3 != 0 && dword_E1653C != 0x29a) {
        if (dword_E5809C == 0 || !dword_E5809C("wasConstructed()", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h", 0xca))
            sub_972290(byte_E580B3, "wasConstructed() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util/Object.h line: 202");
    }
    return sp_Base(sub_4141e0());
}

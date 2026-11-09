// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Desc;
struct B0 { virtual ~B0(); int pad[4]; };
struct B1 { virtual void f1(); };
struct B2 { virtual void f2(); const Desc* descriptor; };
struct B3 { virtual void f3(); int pad[26]; };
struct Base : B0, B1, B2, B3 {
    Base();
    virtual ~Base();
};
extern int count;
struct __declspec(novtable) Described : Base {
    static const Desc& classDescriptor();
    __forceinline Described() { descriptor = &classDescriptor(); ++count; }
};
struct __declspec(novtable) Iface { virtual void g(); int a, b; void* c; Iface() : c(0) {} };
struct __declspec(novtable) Mid : Described, Iface {
    __forceinline Mid() { a = -1; b = -1; }
};
struct Derived : Mid {
    int d;
    Derived();
    virtual ~Derived();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void g();
};
Derived::Derived() : d(5) {}

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long baseCount;
extern int defaultValue;
struct Counted { Counted() { InterlockedIncrement(&baseCount); } };
struct Base : Counted {
    Base(int v) : flag(true), d(defaultValue), v(v) {}
    virtual void f();
    char c4;
    bool flag;
    struct P { void* q; P() : q(0) {} } p;
    int d;
    int v;
};
struct Member {
    void* p;
    Member(int a, int b) : p(0) { assign(a, b); }
    void assign(int a, int b);
    char rest[0x1c];
};
struct Derived : Base {
    int pad14;
    Member m;
    int x, y, z, w;
    Derived(int a, int b, int c);
    virtual void f();
};
Derived::Derived(int a, int b, int c) : Base(c), m(a, b), x(0), y(0), z(0), w(0) {}

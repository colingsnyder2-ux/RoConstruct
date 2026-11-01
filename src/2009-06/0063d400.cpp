// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct Functor { int a[6]; };
struct Quad { int a, b, c, d; Quad() : a(0), b(0), c(0), d(0) {} };
struct Function {
    void* vtable;
    int pad;
    char functor[0x18];
    Function(Functor f) : vtable(0) { assign_to(f); }
    void assign_to(Functor f);
};
extern long g_count;
extern int g_default;
class Counted { public: Counted() { InterlockedIncrement(&g_count); } };
class Base : public Counted {
public:
    Base() {}
    virtual void v0();
    struct Info { char f4; bool flag; int f8; int fc; Info() : flag(true), f8(0), fc(g_default) {} } info;
};
class Derived : public Base {
public:
    Derived(Functor f, int x);
    virtual void v0();
    int f10;
    int f14;
    Function fn;
    Quad quad;
};
Derived::Derived(Functor f, int x) : f10(x), fn(f)
{
}

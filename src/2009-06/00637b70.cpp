// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct Key { int a, b, c, d; };
struct Quad { int a, b, c, d; Quad() : a(0), b(0), c(0), d(0) {} };
struct Data { char bytes[0x18]; };
class Registry { public: bool find(Key k, Data* out); };
extern Registry g_registry;
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
    Derived(Key k, int x);
    virtual void v0();
    int f10;
    int f14;
    Registry* registry;
    int f1c;
    Data data;
    Quad quad;
};
Derived::Derived(Key k, int x) : f10(x), registry(g_registry.find(k, &data) ? &g_registry : 0)
{
}

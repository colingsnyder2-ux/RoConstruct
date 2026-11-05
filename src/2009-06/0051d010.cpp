// from server: 88% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long g_count;
extern int g_val;
struct Counted { Counted() { InterlockedIncrement(&g_count); } };
struct Key { int a, b, c, d; };
struct Reg { bool add(Key k, void* slot); };
extern Reg g;
struct Base : Counted {
    virtual void f();
    char b4;
    bool b5;
    int m8;
    int mc;
    int m10;
    Base(int x) : b5(true), m8(0), mc(g_val), m10(x) {}
};
struct Tex : Base {
    int m14;
    Reg* r;
    int m1c;
    char slot[0x18];
    struct Z { void* a; void* b; void* c; void* d; Z() : a(0), b(0), c(0), d(0) {} } z;
    Tex(Key k, int x);
    virtual void f();
};
Tex::Tex(Key k, int x) : Base(x), r(g.add(k, slot) ? &g : 0) {}

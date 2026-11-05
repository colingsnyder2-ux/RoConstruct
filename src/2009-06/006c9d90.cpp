// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct Counter {
    static long count;
    Counter() { InterlockedIncrement(&count); }
};
extern int gDefault;
struct F { void* fn; void* obj; };
struct Func {
    void* vtable;
    union { double d; char buf[0x18]; } u;
    Func(F f) : vtable(0) { assign_to(f); }
    void assign_to(F f);
};
struct B : Counter {
    virtual void vb();
    bool b4;
    bool b5;
    struct Z { int p; Z() : p(0) {} } f8;
    int fc;
    int f10;
    B(int x) : b5(true), fc(gDefault), f10(x) {}
};
struct D : B {
    Func func;
    int a, b, c, d;
    D(F f, int x);
    virtual void vb();
};
D::D(F f, int x) : B(x), func(f), a(0), b(0), c(0), d(0) {}

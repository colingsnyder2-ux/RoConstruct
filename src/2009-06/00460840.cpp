// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CWnd { void Default(); };
struct W : CWnd {
    char pad[0xb0 - sizeof(CWnd)];
    int mode;
    void a(int);
    void b();
    void c();
    void f();
};
void W::f()
{
    a(0);
    if (mode == 2) b(); else c();
    Default();
}

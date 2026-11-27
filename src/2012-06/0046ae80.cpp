// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc { int a, b; };
Desc g_desc;
struct Sig { void raise(const Desc*); };
int g_value;
struct S {
    char pad[0x144];
    Sig sig;
    void f(int v);
};
void S::f(int v) {
    if (v == g_value) return;
    g_value = v;
    sig.raise(&g_desc);
}

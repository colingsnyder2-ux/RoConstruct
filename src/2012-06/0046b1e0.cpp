// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc { int a, b; };
Desc g_desc;
struct Sig { void raise(const Desc*); };
struct S {
    char pad[192];
    unsigned int value;
    char pad2[0x144 - 192 - sizeof(unsigned int)];
    Sig sig;
    void f(unsigned int v);
};
void S::f(unsigned int v) {
    if (v == value) return;
    value = v;
    sig.raise(&g_desc);
}

// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc { int a, b; };
Desc g_desc;
struct Sig { void raise(const Desc*); };
struct S {
    char pad[184];
    int value;
    char pad2[0x144 - 184 - sizeof(int)];
    Sig sig;
    void f(int v);
};
void S::f(int v) {
    if (v == value) return;
    value = v;
    sig.raise(&g_desc);
}

// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc { int a, b; };
Desc g_desc;
struct Sig { void raise(const Desc*); };
struct S {
    char pad[255];
    unsigned char value;
    char pad2[0x144 - 255 - sizeof(unsigned char)];
    Sig sig;
    void f(unsigned char v);
};
void S::f(unsigned char v) {
    if (v == value) return;
    value = v;
    sig.raise(&g_desc);
}

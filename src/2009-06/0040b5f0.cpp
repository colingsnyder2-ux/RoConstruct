// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040b5f0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0040b5f0* base();
    X_0040b5f0* run() {
    f_0 = (void*)0x8ad73c;
    f_14 = (void*)0x8ad730;
    f_18 = (void*)0x8ad728;
    f_20 = (void*)0x8ad720;
        return base();
    }
};
X_0040b5f0* func_0040b5f0(X_0040b5f0* x) { return x->run(); }

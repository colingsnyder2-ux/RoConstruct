// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005f54b0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005f54b0* base();
    X_005f54b0* run() {
    f_0 = (void*)0x8d69ec;
    f_14 = (void*)0x8d69e0;
    f_18 = (void*)0x8d69d8;
    f_20 = (void*)0x8d69d0;
        return base();
    }
};
X_005f54b0* func_005f54b0(X_005f54b0* x) { return x->run(); }

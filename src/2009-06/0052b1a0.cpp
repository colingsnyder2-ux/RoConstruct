// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0052b1a0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0052b1a0* base();
    X_0052b1a0* run() {
    f_0 = (void*)0x8ca284;
    f_14 = (void*)0x8ca278;
    f_18 = (void*)0x8ca270;
    f_20 = (void*)0x8ca268;
        return base();
    }
};
X_0052b1a0* func_0052b1a0(X_0052b1a0* x) { return x->run(); }

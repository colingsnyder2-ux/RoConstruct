// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006a0ab0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_006a0ab0* base();
    X_006a0ab0* run() {
    f_0 = (void*)0x8e9264;
    f_14 = (void*)0x8e9254;
    f_18 = (void*)0x8e924c;
    f_20 = (void*)0x8e9244;
        return base();
    }
};
X_006a0ab0* func_006a0ab0(X_006a0ab0* x) { return x->run(); }

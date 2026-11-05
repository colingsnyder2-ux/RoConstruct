// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00695e20 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00695e20* base();
    X_00695e20* run() {
    f_0 = (void*)0x8e7a84;
    f_14 = (void*)0x8e7a74;
    f_18 = (void*)0x8e7a6c;
    f_20 = (void*)0x8e7a64;
        return base();
    }
};
X_00695e20* func_00695e20(X_00695e20* x) { return x->run(); }

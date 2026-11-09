// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00667340 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00667340* base();
    X_00667340* run() {
    f_0 = (void*)0x8e2d44;
    f_14 = (void*)0x8e2d34;
    f_18 = (void*)0x8e2d2c;
    f_20 = (void*)0x8e2d24;
        return base();
    }
};
X_00667340* func_00667340(X_00667340* x) { return x->run(); }

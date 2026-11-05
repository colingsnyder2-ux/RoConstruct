// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c9530 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005c9530* base();
    X_005c9530* run() {
    f_0 = (void*)0x8d43c4;
    f_14 = (void*)0x8d43b4;
    f_18 = (void*)0x8d43ac;
    f_20 = (void*)0x8d43a4;
        return base();
    }
};
X_005c9530* func_005c9530(X_005c9530* x) { return x->run(); }

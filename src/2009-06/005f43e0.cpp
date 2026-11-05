// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005f43e0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005f43e0* base();
    X_005f43e0* run() {
    f_0 = (void*)0x8d66cc;
    f_14 = (void*)0x8d66bc;
    f_18 = (void*)0x8d66b4;
    f_20 = (void*)0x8d66ac;
        return base();
    }
};
X_005f43e0* func_005f43e0(X_005f43e0* x) { return x->run(); }

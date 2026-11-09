// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00698340 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_00698340* base();
    X_00698340* run() {
    f_0 = (void*)0x8e7fbc;
    f_14 = (void*)0x8e7fac;
    f_18 = (void*)0x8e7fa4;
    f_20 = (void*)0x8e7f9c;
    f_8c = (void*)0x8e7f84;
        return base();
    }
};
X_00698340* func_00698340(X_00698340* x) { return x->run(); }

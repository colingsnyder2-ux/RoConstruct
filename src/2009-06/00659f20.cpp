// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00659f20 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00659f20* base();
    X_00659f20* run() {
    f_0 = (void*)0x8e116c;
    f_14 = (void*)0x8e115c;
    f_18 = (void*)0x8e1154;
    f_20 = (void*)0x8e114c;
        return base();
    }
};
X_00659f20* func_00659f20(X_00659f20* x) { return x->run(); }

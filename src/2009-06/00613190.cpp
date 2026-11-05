// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00613190 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00613190* base();
    X_00613190* run() {
    f_0 = (void*)0x8d8b3c;
    f_14 = (void*)0x8d8b30;
    f_18 = (void*)0x8d8b28;
    f_20 = (void*)0x8d8b20;
        return base();
    }
};
X_00613190* func_00613190(X_00613190* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006186f0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_006186f0* base();
    X_006186f0* run() {
    f_0 = (void*)0x8d9064;
    f_14 = (void*)0x8d9054;
    f_18 = (void*)0x8d904c;
    f_20 = (void*)0x8d9044;
        return base();
    }
};
X_006186f0* func_006186f0(X_006186f0* x) { return x->run(); }

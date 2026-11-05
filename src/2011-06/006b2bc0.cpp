// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006b2bc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006b2bc0* base();
    X_006b2bc0* run() {
    f_0 = (void*)0xaa4104;
    f_4 = (void*)0xaa40fc;
    f_18 = (void*)0xaa40f0;
    f_1c = (void*)0xaa40e4;
        return base();
    }
};
X_006b2bc0* func_006b2bc0(X_006b2bc0* x) { return x->run(); }

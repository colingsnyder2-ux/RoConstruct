// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005a5db0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005a5db0* base();
    X_005a5db0* run() {
    f_0 = (void*)0xa8d234;
    f_4 = (void*)0xa8d22c;
    f_18 = (void*)0xa8d220;
    f_1c = (void*)0xa8d214;
        return base();
    }
};
X_005a5db0* func_005a5db0(X_005a5db0* x) { return x->run(); }

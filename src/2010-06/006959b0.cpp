// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006959b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006959b0* base();
    X_006959b0* run() {
    f_0 = (void*)0xa3e75c;
    f_4 = (void*)0xa3e754;
    f_18 = (void*)0xa3e748;
    f_1c = (void*)0xa3e73c;
    f_94 = (void*)0xa3e724;
        return base();
    }
};
X_006959b0* func_006959b0(X_006959b0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004db0d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_004db0d0* base();
    X_004db0d0* run() {
    f_0 = (void*)0xa1a804;
    f_4 = (void*)0xa1a7f8;
    f_18 = (void*)0xa1a7ec;
    f_1c = (void*)0xa1a7e0;
    f_94 = (void*)0xa1a7c8;
        return base();
    }
};
X_004db0d0* func_004db0d0(X_004db0d0* x) { return x->run(); }

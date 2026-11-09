// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00629400 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00629400* base();
    X_00629400* run() {
    f_0 = (void*)0xa35304;
    f_4 = (void*)0xa352fc;
    f_18 = (void*)0xa352f0;
    f_1c = (void*)0xa352e4;
    f_94 = (void*)0xa352cc;
        return base();
    }
};
X_00629400* func_00629400(X_00629400* x) { return x->run(); }

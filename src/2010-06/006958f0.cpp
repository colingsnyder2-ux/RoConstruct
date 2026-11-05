// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006958f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006958f0* base();
    X_006958f0* run() {
    f_0 = (void*)0xa3e5ac;
    f_4 = (void*)0xa3e5a4;
    f_18 = (void*)0xa3e598;
    f_1c = (void*)0xa3e58c;
    f_94 = (void*)0xa3e574;
        return base();
    }
};
X_006958f0* func_006958f0(X_006958f0* x) { return x->run(); }

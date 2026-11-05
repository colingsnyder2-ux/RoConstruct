// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006c2490 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006c2490* base();
    X_006c2490* run() {
    f_0 = (void*)0xa43b04;
    f_4 = (void*)0xa43afc;
    f_18 = (void*)0xa43af0;
    f_1c = (void*)0xa43ae4;
    f_94 = (void*)0xa43acc;
        return base();
    }
};
X_006c2490* func_006c2490(X_006c2490* x) { return x->run(); }

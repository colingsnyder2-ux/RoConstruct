// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004af980 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_004af980* base();
    X_004af980* run() {
    f_0 = (void*)0xa1831c;
    f_4 = (void*)0xa18314;
    f_18 = (void*)0xa18308;
    f_1c = (void*)0xa182fc;
    f_94 = (void*)0xa182f4;
        return base();
    }
};
X_004af980* func_004af980(X_004af980* x) { return x->run(); }

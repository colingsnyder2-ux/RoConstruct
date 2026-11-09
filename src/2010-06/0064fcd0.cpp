// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0064fcd0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_0064fcd0* base();
    X_0064fcd0* run() {
    f_0 = (void*)0xa38ec4;
    f_4 = (void*)0xa38eb8;
    f_18 = (void*)0xa38eac;
    f_1c = (void*)0xa38ea0;
    f_94 = (void*)0xa38e94;
        return base();
    }
};
X_0064fcd0* func_0064fcd0(X_0064fcd0* x) { return x->run(); }

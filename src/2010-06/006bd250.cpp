// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006bd250 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006bd250* base();
    X_006bd250* run() {
    f_0 = (void*)0xa430fc;
    f_4 = (void*)0xa430f4;
    f_18 = (void*)0xa430e8;
    f_1c = (void*)0xa430dc;
    f_94 = (void*)0xa430d4;
        return base();
    }
};
X_006bd250* func_006bd250(X_006bd250* x) { return x->run(); }

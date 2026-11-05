// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00695970 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00695970* base();
    X_00695970* run() {
    f_0 = (void*)0xa3e6cc;
    f_4 = (void*)0xa3e6c4;
    f_18 = (void*)0xa3e6b8;
    f_1c = (void*)0xa3e6ac;
    f_94 = (void*)0xa3e694;
        return base();
    }
};
X_00695970* func_00695970(X_00695970* x) { return x->run(); }

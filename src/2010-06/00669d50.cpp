// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00669d50 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00669d50* base();
    X_00669d50* run() {
    f_0 = (void*)0xa3be84;
    f_4 = (void*)0xa3be7c;
    f_18 = (void*)0xa3be70;
    f_1c = (void*)0xa3be64;
    f_94 = (void*)0xa3be5c;
        return base();
    }
};
X_00669d50* func_00669d50(X_00669d50* x) { return x->run(); }

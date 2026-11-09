// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006c25e0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006c25e0* base();
    X_006c25e0* run() {
    f_0 = (void*)0xa43e64;
    f_4 = (void*)0xa43e58;
    f_18 = (void*)0xa43e4c;
    f_1c = (void*)0xa43e40;
    f_94 = (void*)0xa43e28;
        return base();
    }
};
X_006c25e0* func_006c25e0(X_006c25e0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00696090 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00696090* base();
    X_00696090* run() {
    f_0 = (void*)0xa3e90c;
    f_4 = (void*)0xa3e904;
    f_18 = (void*)0xa3e8f8;
    f_1c = (void*)0xa3e8ec;
    f_94 = (void*)0xa3e8d4;
        return base();
    }
};
X_00696090* func_00696090(X_00696090* x) { return x->run(); }

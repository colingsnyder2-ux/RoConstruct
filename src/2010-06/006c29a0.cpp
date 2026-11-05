// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006c29a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006c29a0* base();
    X_006c29a0* run() {
    f_0 = (void*)0xa43dcc;
    f_4 = (void*)0xa43dc4;
    f_18 = (void*)0xa43db8;
    f_1c = (void*)0xa43dac;
    f_94 = (void*)0xa43d94;
        return base();
    }
};
X_006c29a0* func_006c29a0(X_006c29a0* x) { return x->run(); }

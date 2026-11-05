// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0070a880 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_0070a880* base();
    X_0070a880* run() {
    f_0 = (void*)0xa4c05c;
    f_4 = (void*)0xa4c050;
    f_18 = (void*)0xa4c044;
    f_1c = (void*)0xa4c038;
    f_94 = (void*)0xa4c030;
        return base();
    }
};
X_0070a880* func_0070a880(X_0070a880* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00714070 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00714070* base();
    X_00714070* run() {
    f_0 = (void*)0xaaf354;
    f_4 = (void*)0xaaf34c;
    f_18 = (void*)0xaaf340;
    f_1c = (void*)0xaaf334;
        return base();
    }
};
X_00714070* func_00714070(X_00714070* x) { return x->run(); }

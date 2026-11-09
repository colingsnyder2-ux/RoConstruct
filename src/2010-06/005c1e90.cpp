// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c1e90 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c1e90* base();
    X_005c1e90* run() {
    f_0 = (void*)0xa2bdfc;
    f_4 = (void*)0xa2bdf0;
    f_18 = (void*)0xa2bde4;
    f_1c = (void*)0xa2bdd8;
        return base();
    }
};
X_005c1e90* func_005c1e90(X_005c1e90* x) { return x->run(); }

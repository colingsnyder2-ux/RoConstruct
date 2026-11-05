// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c2770 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c2770* base();
    X_005c2770* run() {
    f_0 = (void*)0xa2c05c;
    f_4 = (void*)0xa2c050;
    f_18 = (void*)0xa2c044;
    f_1c = (void*)0xa2c038;
        return base();
    }
};
X_005c2770* func_005c2770(X_005c2770* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c2a20 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c2a20* base();
    X_005c2a20* run() {
    f_0 = (void*)0xa2c0f4;
    f_4 = (void*)0xa2c0e8;
    f_18 = (void*)0xa2c0dc;
    f_1c = (void*)0xa2c0d0;
        return base();
    }
};
X_005c2a20* func_005c2a20(X_005c2a20* x) { return x->run(); }

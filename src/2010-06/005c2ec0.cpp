// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c2ec0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c2ec0* base();
    X_005c2ec0* run() {
    f_0 = (void*)0xa2c224;
    f_4 = (void*)0xa2c218;
    f_18 = (void*)0xa2c20c;
    f_1c = (void*)0xa2c200;
        return base();
    }
};
X_005c2ec0* func_005c2ec0(X_005c2ec0* x) { return x->run(); }

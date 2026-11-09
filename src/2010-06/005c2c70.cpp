// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c2c70 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c2c70* base();
    X_005c2c70* run() {
    f_0 = (void*)0xa2c18c;
    f_4 = (void*)0xa2c180;
    f_18 = (void*)0xa2c174;
    f_1c = (void*)0xa2c168;
        return base();
    }
};
X_005c2c70* func_005c2c70(X_005c2c70* x) { return x->run(); }

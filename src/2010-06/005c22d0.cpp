// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c22d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c22d0* base();
    X_005c22d0* run() {
    f_0 = (void*)0xa2bf2c;
    f_4 = (void*)0xa2bf20;
    f_18 = (void*)0xa2bf14;
    f_1c = (void*)0xa2bf08;
        return base();
    }
};
X_005c22d0* func_005c22d0(X_005c22d0* x) { return x->run(); }

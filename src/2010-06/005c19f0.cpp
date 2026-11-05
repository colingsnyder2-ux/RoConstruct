// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c19f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c19f0* base();
    X_005c19f0* run() {
    f_0 = (void*)0xa2bccc;
    f_4 = (void*)0xa2bcc0;
    f_18 = (void*)0xa2bcb4;
    f_1c = (void*)0xa2bca8;
        return base();
    }
};
X_005c19f0* func_005c19f0(X_005c19f0* x) { return x->run(); }

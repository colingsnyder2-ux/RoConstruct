// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f8250 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006f8250* base();
    X_006f8250* run() {
    f_0 = (void*)0xaaa34c;
    f_4 = (void*)0xaaa344;
    f_18 = (void*)0xaaa338;
    f_1c = (void*)0xaaa32c;
        return base();
    }
};
X_006f8250* func_006f8250(X_006f8250* x) { return x->run(); }

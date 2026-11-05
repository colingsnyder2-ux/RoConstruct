// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00694290 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00694290* base();
    X_00694290* run() {
    f_0 = (void*)0xaa1d04;
    f_4 = (void*)0xaa1cf8;
    f_18 = (void*)0xaa1cec;
    f_1c = (void*)0xaa1ce0;
        return base();
    }
};
X_00694290* func_00694290(X_00694290* x) { return x->run(); }

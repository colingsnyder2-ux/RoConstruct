// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00696040 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00696040* base();
    X_00696040* run() {
    f_0 = (void*)0xaa21dc;
    f_4 = (void*)0xaa21d0;
    f_18 = (void*)0xaa21c4;
    f_1c = (void*)0xaa21b8;
        return base();
    }
};
X_00696040* func_00696040(X_00696040* x) { return x->run(); }

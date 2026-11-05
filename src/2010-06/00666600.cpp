// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00666600 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00666600* base();
    X_00666600* run() {
    f_0 = (void*)0xa3ac2c;
    f_4 = (void*)0xa3ac20;
    f_18 = (void*)0xa3ac14;
    f_1c = (void*)0xa3ac08;
        return base();
    }
};
X_00666600* func_00666600(X_00666600* x) { return x->run(); }

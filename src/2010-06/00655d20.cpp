// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00655d20 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00655d20* base();
    X_00655d20* run() {
    f_0 = (void*)0xa39c04;
    f_4 = (void*)0xa39bfc;
    f_18 = (void*)0xa39bf0;
    f_1c = (void*)0xa39be4;
        return base();
    }
};
X_00655d20* func_00655d20(X_00655d20* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00656f80 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00656f80* base();
    X_00656f80* run() {
    f_0 = (void*)0xa3a014;
    f_4 = (void*)0xa3a008;
    f_18 = (void*)0xa39ffc;
    f_1c = (void*)0xa39ff0;
        return base();
    }
};
X_00656f80* func_00656f80(X_00656f80* x) { return x->run(); }

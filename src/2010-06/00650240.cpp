// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00650240 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00650240* base();
    X_00650240* run() {
    f_0 = (void*)0xa391ac;
    f_4 = (void*)0xa391a4;
    f_18 = (void*)0xa39198;
    f_1c = (void*)0xa3918c;
        return base();
    }
};
X_00650240* func_00650240(X_00650240* x) { return x->run(); }

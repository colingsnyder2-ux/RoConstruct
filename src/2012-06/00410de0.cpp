// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00410de0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00410de0* base();
    X_00410de0* run() {
    f_0 = (void*)0xb4460c;
    f_4 = (void*)0xb44600;
    f_18 = (void*)0xb445f4;
    f_1c = (void*)0xb445e8;
        return base();
    }
};
X_00410de0* func_00410de0(X_00410de0* x) { return x->run(); }

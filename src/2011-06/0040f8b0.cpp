// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040f8b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040f8b0* base();
    X_0040f8b0* run() {
    f_0 = (void*)0xa5c8c4;
    f_4 = (void*)0xa5c8b8;
    f_18 = (void*)0xa5c8ac;
    f_1c = (void*)0xa5c8a0;
        return base();
    }
};
X_0040f8b0* func_0040f8b0(X_0040f8b0* x) { return x->run(); }

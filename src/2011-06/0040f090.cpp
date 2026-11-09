// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040f090 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040f090* base();
    X_0040f090* run() {
    f_0 = (void*)0xa5c6e4;
    f_4 = (void*)0xa5c6d8;
    f_18 = (void*)0xa5c6cc;
    f_1c = (void*)0xa5c6c0;
        return base();
    }
};
X_0040f090* func_0040f090(X_0040f090* x) { return x->run(); }

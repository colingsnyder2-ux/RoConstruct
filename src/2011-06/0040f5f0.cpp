// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040f5f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040f5f0* base();
    X_0040f5f0* run() {
    f_0 = (void*)0xa5c824;
    f_4 = (void*)0xa5c818;
    f_18 = (void*)0xa5c80c;
    f_1c = (void*)0xa5c800;
        return base();
    }
};
X_0040f5f0* func_0040f5f0(X_0040f5f0* x) { return x->run(); }

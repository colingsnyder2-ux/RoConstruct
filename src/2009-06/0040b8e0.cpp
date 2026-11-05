// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040b8e0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0040b8e0* base();
    X_0040b8e0* run() {
    f_0 = (void*)0x8ad7bc;
    f_14 = (void*)0x8ad7b0;
    f_18 = (void*)0x8ad7a8;
    f_20 = (void*)0x8ad7a0;
        return base();
    }
};
X_0040b8e0* func_0040b8e0(X_0040b8e0* x) { return x->run(); }

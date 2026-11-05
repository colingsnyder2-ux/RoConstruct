// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040b330 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0040b330* base();
    X_0040b330* run() {
    f_0 = (void*)0x8ad6bc;
    f_14 = (void*)0x8ad6b0;
    f_18 = (void*)0x8ad6a8;
    f_20 = (void*)0x8ad6a0;
        return base();
    }
};
X_0040b330* func_0040b330(X_0040b330* x) { return x->run(); }

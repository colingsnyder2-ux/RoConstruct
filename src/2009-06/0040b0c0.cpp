// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040b0c0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0040b0c0* base();
    X_0040b0c0* run() {
    f_0 = (void*)0x8ad63c;
    f_14 = (void*)0x8ad630;
    f_18 = (void*)0x8ad628;
    f_20 = (void*)0x8ad620;
        return base();
    }
};
X_0040b0c0* func_0040b0c0(X_0040b0c0* x) { return x->run(); }

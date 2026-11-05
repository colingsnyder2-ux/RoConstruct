// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040b560 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040b560* base();
    X_0040b560* run() {
    f_0 = (void*)0xa00e2c;
    f_4 = (void*)0xa00e20;
    f_18 = (void*)0xa00e14;
    f_1c = (void*)0xa00e08;
        return base();
    }
};
X_0040b560* func_0040b560(X_0040b560* x) { return x->run(); }

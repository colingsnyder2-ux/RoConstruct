// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040b7d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040b7d0* base();
    X_0040b7d0* run() {
    f_0 = (void*)0xa00ec4;
    f_4 = (void*)0xa00eb8;
    f_18 = (void*)0xa00eac;
    f_1c = (void*)0xa00ea0;
        return base();
    }
};
X_0040b7d0* func_0040b7d0(X_0040b7d0* x) { return x->run(); }

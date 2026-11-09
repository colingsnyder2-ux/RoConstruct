// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040b300 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040b300* base();
    X_0040b300* run() {
    f_0 = (void*)0xa00d94;
    f_4 = (void*)0xa00d88;
    f_18 = (void*)0xa00d7c;
    f_1c = (void*)0xa00d70;
        return base();
    }
};
X_0040b300* func_0040b300(X_0040b300* x) { return x->run(); }

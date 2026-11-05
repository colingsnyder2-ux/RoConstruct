// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0066b7b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0066b7b0* base();
    X_0066b7b0* run() {
    f_0 = (void*)0xa3c50c;
    f_4 = (void*)0xa3c504;
    f_18 = (void*)0xa3c4f8;
    f_1c = (void*)0xa3c4ec;
        return base();
    }
};
X_0066b7b0* func_0066b7b0(X_0066b7b0* x) { return x->run(); }

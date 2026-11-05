// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006c07f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006c07f0* base();
    X_006c07f0* run() {
    f_0 = (void*)0xa438bc;
    f_4 = (void*)0xa438b4;
    f_18 = (void*)0xa438a8;
    f_1c = (void*)0xa4389c;
        return base();
    }
};
X_006c07f0* func_006c07f0(X_006c07f0* x) { return x->run(); }

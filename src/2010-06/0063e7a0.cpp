// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0063e7a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0063e7a0* base();
    X_0063e7a0* run() {
    f_0 = (void*)0xa36d24;
    f_4 = (void*)0xa36d1c;
    f_18 = (void*)0xa36d10;
    f_1c = (void*)0xa36d04;
        return base();
    }
};
X_0063e7a0* func_0063e7a0(X_0063e7a0* x) { return x->run(); }

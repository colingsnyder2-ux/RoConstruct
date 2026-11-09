// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0064a470 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0064a470* base();
    X_0064a470* run() {
    f_0 = (void*)0xa994ec;
    f_4 = (void*)0xa994e4;
    f_18 = (void*)0xa994d8;
    f_1c = (void*)0xa994cc;
        return base();
    }
};
X_0064a470* func_0064a470(X_0064a470* x) { return x->run(); }

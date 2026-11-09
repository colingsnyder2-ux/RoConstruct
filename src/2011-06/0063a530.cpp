// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0063a530 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0063a530* base();
    X_0063a530* run() {
    f_0 = (void*)0xa9763c;
    f_4 = (void*)0xa97630;
    f_18 = (void*)0xa97624;
    f_1c = (void*)0xa97618;
        return base();
    }
};
X_0063a530* func_0063a530(X_0063a530* x) { return x->run(); }

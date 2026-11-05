// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0064be40 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0064be40* base();
    X_0064be40* run() {
    f_0 = (void*)0xa38b8c;
    f_4 = (void*)0xa38b80;
    f_18 = (void*)0xa38b74;
    f_1c = (void*)0xa38b68;
        return base();
    }
};
X_0064be40* func_0064be40(X_0064be40* x) { return x->run(); }

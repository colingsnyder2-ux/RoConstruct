// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005fd9a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005fd9a0* base();
    X_005fd9a0* run() {
    f_0 = (void*)0xa305dc;
    f_4 = (void*)0xa305d0;
    f_18 = (void*)0xa305c4;
    f_1c = (void*)0xa305b8;
        return base();
    }
};
X_005fd9a0* func_005fd9a0(X_005fd9a0* x) { return x->run(); }

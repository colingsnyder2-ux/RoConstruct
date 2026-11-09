// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005af230 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005af230* base();
    X_005af230* run() {
    f_0 = (void*)0xa8dbdc;
    f_4 = (void*)0xa8dbd4;
    f_18 = (void*)0xa8dbc8;
    f_1c = (void*)0xa8dbbc;
        return base();
    }
};
X_005af230* func_005af230(X_005af230* x) { return x->run(); }

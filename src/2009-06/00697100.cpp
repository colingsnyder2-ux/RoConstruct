// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00697100 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00697100* base();
    X_00697100* run() {
    f_0 = (void*)0x8e7dec;
    f_14 = (void*)0x8e7ddc;
    f_18 = (void*)0x8e7dd4;
    f_20 = (void*)0x8e7dcc;
        return base();
    }
};
X_00697100* func_00697100(X_00697100* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00678c40 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00678c40* base();
    X_00678c40* run() {
    f_0 = (void*)0x8e484c;
    f_14 = (void*)0x8e483c;
    f_18 = (void*)0x8e4834;
    f_20 = (void*)0x8e482c;
        return base();
    }
};
X_00678c40* func_00678c40(X_00678c40* x) { return x->run(); }

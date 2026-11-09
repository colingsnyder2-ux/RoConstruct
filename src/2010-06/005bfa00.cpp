// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005bfa00 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005bfa00* base();
    X_005bfa00* run() {
    f_0 = (void*)0xa2bae4;
    f_4 = (void*)0xa2badc;
    f_18 = (void*)0xa2bad0;
    f_1c = (void*)0xa2bac4;
        return base();
    }
};
X_005bfa00* func_005bfa00(X_005bfa00* x) { return x->run(); }

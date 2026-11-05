// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005a7c80 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005a7c80* base();
    X_005a7c80* run() {
    f_0 = (void*)0xa8d7c4;
    f_4 = (void*)0xa8d7b8;
    f_18 = (void*)0xa8d7ac;
    f_1c = (void*)0xa8d7a0;
        return base();
    }
};
X_005a7c80* func_005a7c80(X_005a7c80* x) { return x->run(); }

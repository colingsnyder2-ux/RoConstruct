// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005a7010 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005a7010* base();
    X_005a7010* run() {
    f_0 = (void*)0xa8d4ac;
    f_4 = (void*)0xa8d4a4;
    f_18 = (void*)0xa8d498;
    f_1c = (void*)0xa8d48c;
        return base();
    }
};
X_005a7010* func_005a7010(X_005a7010* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005d5a80 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005d5a80* base();
    X_005d5a80* run() {
    f_0 = (void*)0x8d5354;
    f_14 = (void*)0x8d5348;
    f_18 = (void*)0x8d5340;
    f_20 = (void*)0x8d5338;
        return base();
    }
};
X_005d5a80* func_005d5a80(X_005d5a80* x) { return x->run(); }

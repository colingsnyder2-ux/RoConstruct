// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c9b30 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005c9b30* base();
    X_005c9b30* run() {
    f_0 = (void*)0x8d435c;
    f_14 = (void*)0x8d434c;
    f_18 = (void*)0x8d4344;
    f_20 = (void*)0x8d433c;
        return base();
    }
};
X_005c9b30* func_005c9b30(X_005c9b30* x) { return x->run(); }

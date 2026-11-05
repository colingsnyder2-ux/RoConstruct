// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005d8490 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005d8490* base();
    X_005d8490* run() {
    f_0 = (void*)0x8d5514;
    f_14 = (void*)0x8d5504;
    f_18 = (void*)0x8d54fc;
    f_20 = (void*)0x8d54f4;
        return base();
    }
};
X_005d8490* func_005d8490(X_005d8490* x) { return x->run(); }

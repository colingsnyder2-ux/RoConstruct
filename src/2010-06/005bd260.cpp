// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005bd260 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_005bd260* base();
    X_005bd260* run() {
    f_0 = (void*)0xa2b3dc;
    f_4 = (void*)0xa2b3d4;
    f_18 = (void*)0xa2b3c8;
    f_1c = (void*)0xa2b3bc;
    f_94 = (void*)0xa2b3b4;
        return base();
    }
};
X_005bd260* func_005bd260(X_005bd260* x) { return x->run(); }

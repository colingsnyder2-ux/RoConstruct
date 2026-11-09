// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005f5900 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_005f5900* base();
    X_005f5900* run() {
    f_0 = (void*)0xa2f4f4;
    f_4 = (void*)0xa2f4e8;
    f_18 = (void*)0xa2f4dc;
    f_1c = (void*)0xa2f4d0;
    f_94 = (void*)0xa2f4c8;
        return base();
    }
};
X_005f5900* func_005f5900(X_005f5900* x) { return x->run(); }

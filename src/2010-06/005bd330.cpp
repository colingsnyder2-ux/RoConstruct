// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005bd330 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_005bd330* base();
    X_005bd330* run() {
    f_0 = (void*)0xa2b4b4;
    f_4 = (void*)0xa2b4ac;
    f_18 = (void*)0xa2b4a0;
    f_1c = (void*)0xa2b494;
    f_94 = (void*)0xa2b48c;
        return base();
    }
};
X_005bd330* func_005bd330(X_005bd330* x) { return x->run(); }

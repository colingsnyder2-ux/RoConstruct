// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004da450 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_004da450* base();
    X_004da450* run() {
    f_0 = (void*)0xa1a63c;
    f_4 = (void*)0xa1a634;
    f_18 = (void*)0xa1a628;
    f_1c = (void*)0xa1a61c;
    f_94 = (void*)0xa1a5ec;
        return base();
    }
};
X_004da450* func_004da450(X_004da450* x) { return x->run(); }

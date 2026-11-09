// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f9c30 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006f9c30* base();
    X_006f9c30* run() {
    f_0 = (void*)0xaaa8bc;
    f_4 = (void*)0xaaa8b0;
    f_18 = (void*)0xaaa8a4;
    f_1c = (void*)0xaaa898;
    f_90 = (void*)0xaaa870;
        return base();
    }
};
X_006f9c30* func_006f9c30(X_006f9c30* x) { return x->run(); }

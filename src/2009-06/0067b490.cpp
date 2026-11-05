// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0067b490 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_0067b490* base();
    X_0067b490* run() {
    f_0 = (void*)0x8e502c;
    f_14 = (void*)0x8e501c;
    f_18 = (void*)0x8e5014;
    f_20 = (void*)0x8e500c;
    f_8c = (void*)0x8e4ff4;
        return base();
    }
};
X_0067b490* func_0067b490(X_0067b490* x) { return x->run(); }

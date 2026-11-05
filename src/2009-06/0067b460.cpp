// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0067b460 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_0067b460* base();
    X_0067b460* run() {
    f_0 = (void*)0x8e4fac;
    f_14 = (void*)0x8e4f9c;
    f_18 = (void*)0x8e4f94;
    f_20 = (void*)0x8e4f8c;
    f_8c = (void*)0x8e4f74;
        return base();
    }
};
X_0067b460* func_0067b460(X_0067b460* x) { return x->run(); }

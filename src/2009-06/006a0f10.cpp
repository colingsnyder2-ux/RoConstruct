// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006a0f10 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_006a0f10* base();
    X_006a0f10* run() {
    f_0 = (void*)0x8e9404;
    f_14 = (void*)0x8e93f8;
    f_18 = (void*)0x8e93f0;
    f_20 = (void*)0x8e93e8;
        return base();
    }
};
X_006a0f10* func_006a0f10(X_006a0f10* x) { return x->run(); }

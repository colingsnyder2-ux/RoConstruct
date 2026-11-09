// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0051d5a0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0051d5a0* base();
    X_0051d5a0* run() {
    f_0 = (void*)0x8c9e94;
    f_14 = (void*)0x8c9e84;
    f_18 = (void*)0x8c9e7c;
    f_20 = (void*)0x8c9e74;
        return base();
    }
};
X_0051d5a0* func_0051d5a0(X_0051d5a0* x) { return x->run(); }

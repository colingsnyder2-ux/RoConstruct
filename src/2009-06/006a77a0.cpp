// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006a77a0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_006a77a0* base();
    X_006a77a0* run() {
    f_0 = (void*)0x8ea214;
    f_14 = (void*)0x8ea208;
    f_18 = (void*)0x8ea200;
    f_20 = (void*)0x8ea1f8;
    f_8c = (void*)0x8ea1f0;
        return base();
    }
};
X_006a77a0* func_006a77a0(X_006a77a0* x) { return x->run(); }

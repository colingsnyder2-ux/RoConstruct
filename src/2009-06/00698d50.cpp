// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00698d50 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_00698d50* base();
    X_00698d50* run() {
    f_0 = (void*)0x8e8224;
    f_14 = (void*)0x8e8214;
    f_18 = (void*)0x8e820c;
    f_20 = (void*)0x8e8204;
    f_8c = (void*)0x8e81ec;
        return base();
    }
};
X_00698d50* func_00698d50(X_00698d50* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00673420 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_00673420* base();
    X_00673420* run() {
    f_0 = (void*)0x8e3e74;
    f_14 = (void*)0x8e3e68;
    f_18 = (void*)0x8e3e60;
    f_20 = (void*)0x8e3e58;
    f_8c = (void*)0x8e3e50;
        return base();
    }
};
X_00673420* func_00673420(X_00673420* x) { return x->run(); }

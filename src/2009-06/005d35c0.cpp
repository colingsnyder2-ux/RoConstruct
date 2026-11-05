// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005d35c0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005d35c0* base();
    X_005d35c0* run() {
    f_0 = (void*)0x8d5234;
    f_14 = (void*)0x8d5228;
    f_18 = (void*)0x8d5220;
    f_20 = (void*)0x8d5218;
        return base();
    }
};
X_005d35c0* func_005d35c0(X_005d35c0* x) { return x->run(); }

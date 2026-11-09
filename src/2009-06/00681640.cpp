// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00681640 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00681640* base();
    X_00681640* run() {
    f_0 = (void*)0x8e5c84;
    f_14 = (void*)0x8e5c74;
    f_18 = (void*)0x8e5c6c;
    f_20 = (void*)0x8e5c64;
        return base();
    }
};
X_00681640* func_00681640(X_00681640* x) { return x->run(); }

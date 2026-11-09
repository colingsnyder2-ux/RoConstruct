// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005f5950 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005f5950* base();
    X_005f5950* run() {
    f_0 = (void*)0x8d6aec;
    f_14 = (void*)0x8d6ae0;
    f_18 = (void*)0x8d6ad8;
    f_20 = (void*)0x8d6ad0;
        return base();
    }
};
X_005f5950* func_005f5950(X_005f5950* x) { return x->run(); }

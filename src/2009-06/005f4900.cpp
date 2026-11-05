// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005f4900 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005f4900* base();
    X_005f4900* run() {
    f_0 = (void*)0x8d676c;
    f_14 = (void*)0x8d675c;
    f_18 = (void*)0x8d6754;
    f_20 = (void*)0x8d674c;
        return base();
    }
};
X_005f4900* func_005f4900(X_005f4900* x) { return x->run(); }

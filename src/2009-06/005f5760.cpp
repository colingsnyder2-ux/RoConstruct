// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005f5760 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_005f5760* base();
    X_005f5760* run() {
    f_0 = (void*)0x8d6a6c;
    f_14 = (void*)0x8d6a60;
    f_18 = (void*)0x8d6a58;
    f_20 = (void*)0x8d6a50;
        return base();
    }
};
X_005f5760* func_005f5760(X_005f5760* x) { return x->run(); }

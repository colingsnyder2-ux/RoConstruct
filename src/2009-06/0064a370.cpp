// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0064a370 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_0064a370* base();
    X_0064a370* run() {
    f_0 = (void*)0x8deddc;
    f_14 = (void*)0x8dedcc;
    f_18 = (void*)0x8dedc4;
    f_20 = (void*)0x8dedbc;
    f_8c = (void*)0x8deda4;
        return base();
    }
};
X_0064a370* func_0064a370(X_0064a370* x) { return x->run(); }

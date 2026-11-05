// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00614790 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00614790* base();
    X_00614790* run() {
    f_0 = (void*)0x8d8c7c;
    f_14 = (void*)0x8d8c6c;
    f_18 = (void*)0x8d8c64;
    f_20 = (void*)0x8d8c5c;
        return base();
    }
};
X_00614790* func_00614790(X_00614790* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004d7270 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_004d7270* base();
    X_004d7270* run() {
    f_0 = (void*)0x8c60bc;
    f_14 = (void*)0x8c60ac;
    f_18 = (void*)0x8c60a4;
    f_20 = (void*)0x8c609c;
        return base();
    }
};
X_004d7270* func_004d7270(X_004d7270* x) { return x->run(); }

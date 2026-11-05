// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00658750 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00658750* base();
    X_00658750* run() {
    f_0 = (void*)0x8e0e1c;
    f_14 = (void*)0x8e0e0c;
    f_18 = (void*)0x8e0e04;
    f_20 = (void*)0x8e0dfc;
        return base();
    }
};
X_00658750* func_00658750(X_00658750* x) { return x->run(); }

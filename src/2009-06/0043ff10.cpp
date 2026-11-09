// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0043ff10 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0043ff10* base();
    X_0043ff10* run() {
    f_0 = (void*)0x8b61bc;
    f_14 = (void*)0x8b61ac;
    f_18 = (void*)0x8b61a4;
    f_20 = (void*)0x8b619c;
        return base();
    }
};
X_0043ff10* func_0043ff10(X_0043ff10* x) { return x->run(); }

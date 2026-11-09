// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00658850 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_00658850* base();
    X_00658850* run() {
    f_0 = (void*)0x8e0efc;
    f_14 = (void*)0x8e0ef0;
    f_18 = (void*)0x8e0ee8;
    f_20 = (void*)0x8e0ee0;
    f_8c = (void*)0x8e0ed4;
        return base();
    }
};
X_00658850* func_00658850(X_00658850* x) { return x->run(); }

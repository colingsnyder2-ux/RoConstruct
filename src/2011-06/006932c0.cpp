// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006932c0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006932c0* base();
    X_006932c0* run() {
    f_0 = (void*)0xaa176c;
    f_4 = (void*)0xaa1760;
    f_18 = (void*)0xaa1754;
    f_1c = (void*)0xaa1748;
    f_90 = (void*)0xaa1740;
        return base();
    }
};
X_006932c0* func_006932c0(X_006932c0* x) { return x->run(); }

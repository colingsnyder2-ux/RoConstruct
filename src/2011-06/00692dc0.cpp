// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00692dc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_00692dc0* base();
    X_00692dc0* run() {
    f_0 = (void*)0xaa1564;
    f_4 = (void*)0xaa155c;
    f_18 = (void*)0xaa1550;
    f_1c = (void*)0xaa1544;
    f_90 = (void*)0xaa153c;
        return base();
    }
};
X_00692dc0* func_00692dc0(X_00692dc0* x) { return x->run(); }

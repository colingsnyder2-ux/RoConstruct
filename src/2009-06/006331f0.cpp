// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006331f0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_006331f0* base();
    X_006331f0* run() {
    f_0 = (void*)0x8db324;
    f_14 = (void*)0x8db318;
    f_18 = (void*)0x8db310;
    f_20 = (void*)0x8db308;
        return base();
    }
};
X_006331f0* func_006331f0(X_006331f0* x) { return x->run(); }

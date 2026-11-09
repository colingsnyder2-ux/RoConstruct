// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006513c0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_006513c0* base();
    X_006513c0* run() {
    f_0 = (void*)0x8df984;
    f_14 = (void*)0x8df974;
    f_18 = (void*)0x8df96c;
    f_20 = (void*)0x8df964;
        return base();
    }
};
X_006513c0* func_006513c0(X_006513c0* x) { return x->run(); }

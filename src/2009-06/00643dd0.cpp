// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00643dd0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00643dd0* base();
    X_00643dd0* run() {
    f_0 = (void*)0x8de36c;
    f_14 = (void*)0x8de35c;
    f_18 = (void*)0x8de354;
    f_20 = (void*)0x8de34c;
        return base();
    }
};
X_00643dd0* func_00643dd0(X_00643dd0* x) { return x->run(); }

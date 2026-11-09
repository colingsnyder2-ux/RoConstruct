// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004dae70 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004dae70* base();
    X_004dae70* run() {
    f_0 = (void*)0xa1a75c;
    f_4 = (void*)0xa1a750;
    f_18 = (void*)0xa1a744;
    f_1c = (void*)0xa1a738;
        return base();
    }
};
X_004dae70* func_004dae70(X_004dae70* x) { return x->run(); }

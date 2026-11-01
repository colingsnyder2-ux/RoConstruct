// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004115f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004115f0* base();
    X_004115f0* run() {
    f_0 = (void*)0xb4473c;
    f_4 = (void*)0xb44730;
    f_18 = (void*)0xb44724;
    f_1c = (void*)0xb44718;
        return base();
    }
};
X_004115f0* func_004115f0(X_004115f0* x) { return x->run(); }

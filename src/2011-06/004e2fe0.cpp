// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004e2fe0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004e2fe0* base();
    X_004e2fe0* run() {
    f_0 = (void*)0xa79f64;
    f_4 = (void*)0xa79f58;
    f_18 = (void*)0xa79f4c;
    f_1c = (void*)0xa79f40;
        return base();
    }
};
X_004e2fe0* func_004e2fe0(X_004e2fe0* x) { return x->run(); }

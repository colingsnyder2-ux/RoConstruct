// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d8b10 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006d8b10* base();
    X_006d8b10* run() {
    f_0 = (void*)0xa462ac;
    f_4 = (void*)0xa462a0;
    f_18 = (void*)0xa46294;
    f_1c = (void*)0xa46288;
        return base();
    }
};
X_006d8b10* func_006d8b10(X_006d8b10* x) { return x->run(); }

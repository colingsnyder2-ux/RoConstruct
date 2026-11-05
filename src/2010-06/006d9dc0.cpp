// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d9dc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006d9dc0* base();
    X_006d9dc0* run() {
    f_0 = (void*)0xa4692c;
    f_4 = (void*)0xa46920;
    f_18 = (void*)0xa46914;
    f_1c = (void*)0xa46908;
        return base();
    }
};
X_006d9dc0* func_006d9dc0(X_006d9dc0* x) { return x->run(); }

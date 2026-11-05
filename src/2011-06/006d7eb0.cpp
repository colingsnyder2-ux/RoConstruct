// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d7eb0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006d7eb0* base();
    X_006d7eb0* run() {
    f_0 = (void*)0xaa746c;
    f_4 = (void*)0xaa7460;
    f_18 = (void*)0xaa7454;
    f_1c = (void*)0xaa7448;
        return base();
    }
};
X_006d7eb0* func_006d7eb0(X_006d7eb0* x) { return x->run(); }

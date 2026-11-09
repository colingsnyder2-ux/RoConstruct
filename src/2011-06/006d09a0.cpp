// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d09a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006d09a0* base();
    X_006d09a0* run() {
    f_0 = (void*)0xaa57dc;
    f_4 = (void*)0xaa57d0;
    f_18 = (void*)0xaa57c4;
    f_1c = (void*)0xaa57b8;
        return base();
    }
};
X_006d09a0* func_006d09a0(X_006d09a0* x) { return x->run(); }

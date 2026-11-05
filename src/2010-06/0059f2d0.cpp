// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0059f2d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0059f2d0* base();
    X_0059f2d0* run() {
    f_0 = (void*)0xa2a31c;
    f_4 = (void*)0xa2a314;
    f_18 = (void*)0xa2a308;
    f_1c = (void*)0xa2a2fc;
        return base();
    }
};
X_0059f2d0* func_0059f2d0(X_0059f2d0* x) { return x->run(); }

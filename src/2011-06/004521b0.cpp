// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004521b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004521b0* base();
    X_004521b0* run() {
    f_0 = (void*)0xa6cabc;
    f_4 = (void*)0xa6cab0;
    f_18 = (void*)0xa6caa4;
    f_1c = (void*)0xa6ca98;
        return base();
    }
};
X_004521b0* func_004521b0(X_004521b0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00409ae0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00409ae0* base();
    X_00409ae0* run() {
    f_0 = (void*)0xa009ac;
    f_4 = (void*)0xa009a0;
    f_18 = (void*)0xa00994;
    f_1c = (void*)0xa00988;
        return base();
    }
};
X_00409ae0* func_00409ae0(X_00409ae0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006670d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006670d0* base();
    X_006670d0* run() {
    f_0 = (void*)0xa9c104;
    f_4 = (void*)0xa9c0fc;
    f_18 = (void*)0xa9c0f0;
    f_1c = (void*)0xa9c0e4;
        return base();
    }
};
X_006670d0* func_006670d0(X_006670d0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c1be0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c1be0* base();
    X_005c1be0* run() {
    f_0 = (void*)0xa2bd64;
    f_4 = (void*)0xa2bd58;
    f_18 = (void*)0xa2bd4c;
    f_1c = (void*)0xa2bd40;
        return base();
    }
};
X_005c1be0* func_005c1be0(X_005c1be0* x) { return x->run(); }

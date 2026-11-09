// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006477e0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006477e0* base();
    X_006477e0* run() {
    f_0 = (void*)0xa989c4;
    f_4 = (void*)0xa989b8;
    f_18 = (void*)0xa989ac;
    f_1c = (void*)0xa989a0;
        return base();
    }
};
X_006477e0* func_006477e0(X_006477e0* x) { return x->run(); }

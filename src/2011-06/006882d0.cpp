// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006882d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006882d0* base();
    X_006882d0* run() {
    f_0 = (void*)0xa9f09c;
    f_4 = (void*)0xa9f094;
    f_18 = (void*)0xa9f088;
    f_1c = (void*)0xa9f07c;
        return base();
    }
};
X_006882d0* func_006882d0(X_006882d0* x) { return x->run(); }

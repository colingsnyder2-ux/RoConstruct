// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d8640 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006d8640* base();
    X_006d8640* run() {
    f_0 = (void*)0xa4616c;
    f_4 = (void*)0xa46160;
    f_18 = (void*)0xa46154;
    f_1c = (void*)0xa46148;
    f_94 = (void*)0xa4613c;
        return base();
    }
};
X_006d8640* func_006d8640(X_006d8640* x) { return x->run(); }

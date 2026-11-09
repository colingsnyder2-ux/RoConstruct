// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005a2a60 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005a2a60* base();
    X_005a2a60* run() {
    f_0 = (void*)0xa8cc9c;
    f_4 = (void*)0xa8cc94;
    f_18 = (void*)0xa8cc88;
    f_1c = (void*)0xa8cc7c;
        return base();
    }
};
X_005a2a60* func_005a2a60(X_005a2a60* x) { return x->run(); }

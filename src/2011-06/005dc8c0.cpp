// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005dc8c0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005dc8c0* base();
    X_005dc8c0* run() {
    f_0 = (void*)0xa90074;
    f_4 = (void*)0xa90068;
    f_18 = (void*)0xa9005c;
    f_1c = (void*)0xa90050;
        return base();
    }
};
X_005dc8c0* func_005dc8c0(X_005dc8c0* x) { return x->run(); }

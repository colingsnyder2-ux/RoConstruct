// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005c2080 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005c2080* base();
    X_005c2080* run() {
    f_0 = (void*)0xa2be94;
    f_4 = (void*)0xa2be88;
    f_18 = (void*)0xa2be7c;
    f_1c = (void*)0xa2be70;
        return base();
    }
};
X_005c2080* func_005c2080(X_005c2080* x) { return x->run(); }

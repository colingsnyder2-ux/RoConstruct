// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005e98f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005e98f0* base();
    X_005e98f0* run() {
    f_0 = (void*)0xa2e9f4;
    f_4 = (void*)0xa2e9ec;
    f_18 = (void*)0xa2e9e0;
    f_1c = (void*)0xa2e9d4;
        return base();
    }
};
X_005e98f0* func_005e98f0(X_005e98f0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040bee0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040bee0* base();
    X_0040bee0* run() {
    f_0 = (void*)0xa5c04c;
    f_4 = (void*)0xa5c040;
    f_18 = (void*)0xa5c034;
    f_1c = (void*)0xa5c028;
        return base();
    }
};
X_0040bee0* func_0040bee0(X_0040bee0* x) { return x->run(); }

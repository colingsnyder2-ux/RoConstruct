// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006bdac0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006bdac0* base();
    X_006bdac0* run() {
    f_0 = (void*)0xa432d4;
    f_4 = (void*)0xa432cc;
    f_18 = (void*)0xa432c0;
    f_1c = (void*)0xa432b4;
        return base();
    }
};
X_006bdac0* func_006bdac0(X_006bdac0* x) { return x->run(); }

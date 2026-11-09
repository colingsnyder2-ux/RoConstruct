// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d93f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006d93f0* base();
    X_006d93f0* run() {
    f_0 = (void*)0xa46534;
    f_4 = (void*)0xa4652c;
    f_18 = (void*)0xa46520;
    f_1c = (void*)0xa46514;
        return base();
    }
};
X_006d93f0* func_006d93f0(X_006d93f0* x) { return x->run(); }

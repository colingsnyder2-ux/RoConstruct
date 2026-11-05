// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f5cb0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006f5cb0* base();
    X_006f5cb0* run() {
    f_0 = (void*)0xaa9cb4;
    f_4 = (void*)0xaa9ca8;
    f_18 = (void*)0xaa9c9c;
    f_1c = (void*)0xaa9c90;
        return base();
    }
};
X_006f5cb0* func_006f5cb0(X_006f5cb0* x) { return x->run(); }

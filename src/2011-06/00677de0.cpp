// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00677de0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00677de0* base();
    X_00677de0* run() {
    f_0 = (void*)0xa9d534;
    f_4 = (void*)0xa9d52c;
    f_18 = (void*)0xa9d520;
    f_1c = (void*)0xa9d514;
        return base();
    }
};
X_00677de0* func_00677de0(X_00677de0* x) { return x->run(); }

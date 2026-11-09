// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00693250 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_00693250* base();
    X_00693250* run() {
    f_0 = (void*)0xaa16d4;
    f_4 = (void*)0xaa16cc;
    f_18 = (void*)0xaa16c0;
    f_1c = (void*)0xaa16b4;
    f_90 = (void*)0xaa16ac;
        return base();
    }
};
X_00693250* func_00693250(X_00693250* x) { return x->run(); }

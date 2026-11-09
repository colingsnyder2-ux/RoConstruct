// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00411a30 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00411a30* base();
    X_00411a30* run() {
    f_0 = (void*)0xb447d4;
    f_4 = (void*)0xb447c8;
    f_18 = (void*)0xb447bc;
    f_1c = (void*)0xb447b0;
        return base();
    }
};
X_00411a30* func_00411a30(X_00411a30* x) { return x->run(); }

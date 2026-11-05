// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004d6b40 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004d6b40* base();
    X_004d6b40* run() {
    f_0 = (void*)0xa19efc;
    f_4 = (void*)0xa19ef4;
    f_18 = (void*)0xa19ee8;
    f_1c = (void*)0xa19edc;
        return base();
    }
};
X_004d6b40* func_004d6b40(X_004d6b40* x) { return x->run(); }

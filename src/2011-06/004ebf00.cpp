// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004ebf00 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004ebf00* base();
    X_004ebf00* run() {
    f_0 = (void*)0xa7ad54;
    f_4 = (void*)0xa7ad48;
    f_18 = (void*)0xa7ad3c;
    f_1c = (void*)0xa7ad30;
        return base();
    }
};
X_004ebf00* func_004ebf00(X_004ebf00* x) { return x->run(); }

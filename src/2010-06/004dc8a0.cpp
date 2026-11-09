// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004dc8a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004dc8a0* base();
    X_004dc8a0* run() {
    f_0 = (void*)0xa1aafc;
    f_4 = (void*)0xa1aaf4;
    f_18 = (void*)0xa1aae8;
    f_1c = (void*)0xa1aadc;
        return base();
    }
};
X_004dc8a0* func_004dc8a0(X_004dc8a0* x) { return x->run(); }

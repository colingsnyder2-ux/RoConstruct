// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004af720 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_004af720* base();
    X_004af720* run() {
    f_0 = (void*)0xa18274;
    f_4 = (void*)0xa18268;
    f_18 = (void*)0xa1825c;
    f_1c = (void*)0xa18250;
    f_94 = (void*)0xa18248;
        return base();
    }
};
X_004af720* func_004af720(X_004af720* x) { return x->run(); }

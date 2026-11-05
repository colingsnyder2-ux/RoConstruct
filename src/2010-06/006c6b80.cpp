// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006c6b80 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006c6b80* base();
    X_006c6b80* run() {
    f_0 = (void*)0xa44c2c;
    f_4 = (void*)0xa44c24;
    f_18 = (void*)0xa44c18;
    f_1c = (void*)0xa44c0c;
        return base();
    }
};
X_006c6b80* func_006c6b80(X_006c6b80* x) { return x->run(); }

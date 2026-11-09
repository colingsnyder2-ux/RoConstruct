// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0069d200 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0069d200* base();
    X_0069d200* run() {
    f_0 = (void*)0x8e8e3c;
    f_14 = (void*)0x8e8e2c;
    f_18 = (void*)0x8e8e24;
    f_20 = (void*)0x8e8e1c;
        return base();
    }
};
X_0069d200* func_0069d200(X_0069d200* x) { return x->run(); }

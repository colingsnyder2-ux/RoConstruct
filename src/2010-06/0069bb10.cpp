// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0069bb10 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0069bb10* base();
    X_0069bb10* run() {
    f_0 = (void*)0xa3f36c;
    f_4 = (void*)0xa3f364;
    f_18 = (void*)0xa3f358;
    f_1c = (void*)0xa3f34c;
        return base();
    }
};
X_0069bb10* func_0069bb10(X_0069bb10* x) { return x->run(); }

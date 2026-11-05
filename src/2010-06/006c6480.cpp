// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006c6480 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006c6480* base();
    X_006c6480* run() {
    f_0 = (void*)0xa44b0c;
    f_4 = (void*)0xa44b04;
    f_18 = (void*)0xa44af8;
    f_1c = (void*)0xa44aec;
        return base();
    }
};
X_006c6480* func_006c6480(X_006c6480* x) { return x->run(); }

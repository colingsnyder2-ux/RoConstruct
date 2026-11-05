// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005992f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005992f0* base();
    X_005992f0* run() {
    f_0 = (void*)0xa8a23c;
    f_4 = (void*)0xa8a234;
    f_18 = (void*)0xa8a228;
    f_1c = (void*)0xa8a21c;
        return base();
    }
};
X_005992f0* func_005992f0(X_005992f0* x) { return x->run(); }

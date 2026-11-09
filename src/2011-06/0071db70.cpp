// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0071db70 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0071db70* base();
    X_0071db70* run() {
    f_0 = (void*)0xab17bc;
    f_4 = (void*)0xab17b0;
    f_18 = (void*)0xab17a4;
    f_1c = (void*)0xab1798;
        return base();
    }
};
X_0071db70* func_0071db70(X_0071db70* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0061a670 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0061a670* base();
    X_0061a670* run() {
    f_0 = (void*)0xa94604;
    f_4 = (void*)0xa945f8;
    f_18 = (void*)0xa945ec;
    f_1c = (void*)0xa945e0;
        return base();
    }
};
X_0061a670* func_0061a670(X_0061a670* x) { return x->run(); }

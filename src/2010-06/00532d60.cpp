// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00532d60 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00532d60* base();
    X_00532d60* run() {
    f_0 = (void*)0xa1f074;
    f_4 = (void*)0xa1f06c;
    f_18 = (void*)0xa1f060;
    f_1c = (void*)0xa1f054;
        return base();
    }
};
X_00532d60* func_00532d60(X_00532d60* x) { return x->run(); }

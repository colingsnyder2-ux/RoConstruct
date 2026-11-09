// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006c4d60 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006c4d60* base();
    X_006c4d60* run() {
    f_0 = (void*)0xa446cc;
    f_4 = (void*)0xa446c4;
    f_18 = (void*)0xa446b8;
    f_1c = (void*)0xa446ac;
        return base();
    }
};
X_006c4d60* func_006c4d60(X_006c4d60* x) { return x->run(); }

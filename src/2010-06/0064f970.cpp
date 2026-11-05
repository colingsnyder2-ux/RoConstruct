// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0064f970 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_0064f970* base();
    X_0064f970* run() {
    f_0 = (void*)0xa38e3c;
    f_4 = (void*)0xa38e34;
    f_18 = (void*)0xa38e28;
    f_1c = (void*)0xa38e1c;
    f_94 = (void*)0xa38e10;
        return base();
    }
};
X_0064f970* func_0064f970(X_0064f970* x) { return x->run(); }

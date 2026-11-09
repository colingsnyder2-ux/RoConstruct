// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005fe630 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005fe630* base();
    X_005fe630* run() {
    f_0 = (void*)0xa3077c;
    f_4 = (void*)0xa30770;
    f_18 = (void*)0xa30764;
    f_1c = (void*)0xa30758;
        return base();
    }
};
X_005fe630* func_005fe630(X_005fe630* x) { return x->run(); }

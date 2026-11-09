// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005db450 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005db450* base();
    X_005db450* run() {
    f_0 = (void*)0xa8fcb4;
    f_4 = (void*)0xa8fca8;
    f_18 = (void*)0xa8fc9c;
    f_1c = (void*)0xa8fc90;
        return base();
    }
};
X_005db450* func_005db450(X_005db450* x) { return x->run(); }

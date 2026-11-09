// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00679170 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00679170* base();
    X_00679170* run() {
    f_0 = (void*)0xa9d8ec;
    f_4 = (void*)0xa9d8e0;
    f_18 = (void*)0xa9d8d4;
    f_1c = (void*)0xa9d8c8;
        return base();
    }
};
X_00679170* func_00679170(X_00679170* x) { return x->run(); }

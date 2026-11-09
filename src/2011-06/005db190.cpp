// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005db190 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_005db190* base();
    X_005db190* run() {
    f_0 = (void*)0xa8fc14;
    f_4 = (void*)0xa8fc08;
    f_18 = (void*)0xa8fbfc;
    f_1c = (void*)0xa8fbf0;
        return base();
    }
};
X_005db190* func_005db190(X_005db190* x) { return x->run(); }

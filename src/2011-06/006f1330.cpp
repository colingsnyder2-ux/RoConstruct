// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f1330 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006f1330* base();
    X_006f1330* run() {
    f_0 = (void*)0xaa930c;
    f_4 = (void*)0xaa9304;
    f_18 = (void*)0xaa92f8;
    f_1c = (void*)0xaa92ec;
        return base();
    }
};
X_006f1330* func_006f1330(X_006f1330* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00695920 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00695920* base();
    X_00695920* run() {
    f_0 = (void*)0xaa20c4;
    f_4 = (void*)0xaa20bc;
    f_18 = (void*)0xaa20b0;
    f_1c = (void*)0xaa20a4;
        return base();
    }
};
X_00695920* func_00695920(X_00695920* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00669d80 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00669d80* base();
    X_00669d80* run() {
    f_0 = (void*)0xa3bdfc;
    f_4 = (void*)0xa3bdf4;
    f_18 = (void*)0xa3bde8;
    f_1c = (void*)0xa3bddc;
    f_94 = (void*)0xa3bdd4;
        return base();
    }
};
X_00669d80* func_00669d80(X_00669d80* x) { return x->run(); }

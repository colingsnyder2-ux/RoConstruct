// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00669c60 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00669c60* base();
    X_00669c60* run() {
    f_0 = (void*)0xa3bd74;
    f_4 = (void*)0xa3bd6c;
    f_18 = (void*)0xa3bd60;
    f_1c = (void*)0xa3bd54;
    f_94 = (void*)0xa3bd4c;
        return base();
    }
};
X_00669c60* func_00669c60(X_00669c60* x) { return x->run(); }

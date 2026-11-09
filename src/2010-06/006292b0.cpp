// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006292b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_006292b0* base();
    X_006292b0* run() {
    f_0 = (void*)0xa3522c;
    f_4 = (void*)0xa35224;
    f_18 = (void*)0xa35218;
    f_1c = (void*)0xa3520c;
    f_94 = (void*)0xa351f4;
        return base();
    }
};
X_006292b0* func_006292b0(X_006292b0* x) { return x->run(); }

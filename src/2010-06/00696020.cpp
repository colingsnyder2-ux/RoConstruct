// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00696020 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00696020* base();
    X_00696020* run() {
    f_0 = (void*)0xa3e87c;
    f_4 = (void*)0xa3e874;
    f_18 = (void*)0xa3e868;
    f_1c = (void*)0xa3e85c;
    f_94 = (void*)0xa3e844;
        return base();
    }
};
X_00696020* func_00696020(X_00696020* x) { return x->run(); }

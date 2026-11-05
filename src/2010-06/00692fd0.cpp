// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00692fd0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00692fd0* base();
    X_00692fd0* run() {
    f_0 = (void*)0xa3de14;
    f_4 = (void*)0xa3de0c;
    f_18 = (void*)0xa3de00;
    f_1c = (void*)0xa3ddf4;
        return base();
    }
};
X_00692fd0* func_00692fd0(X_00692fd0* x) { return x->run(); }

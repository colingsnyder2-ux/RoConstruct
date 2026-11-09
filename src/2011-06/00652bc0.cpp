// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00652bc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_00652bc0* base();
    X_00652bc0* run() {
    f_0 = (void*)0xa9a3c4;
    f_4 = (void*)0xa9a3b8;
    f_18 = (void*)0xa9a3ac;
    f_1c = (void*)0xa9a3a0;
    f_90 = (void*)0xa9a378;
        return base();
    }
};
X_00652bc0* func_00652bc0(X_00652bc0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d31d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006d31d0* base();
    X_006d31d0* run() {
    f_0 = (void*)0xaa62fc;
    f_4 = (void*)0xaa62f4;
    f_18 = (void*)0xaa62e8;
    f_1c = (void*)0xaa62dc;
    f_90 = (void*)0xaa62b4;
        return base();
    }
};
X_006d31d0* func_006d31d0(X_006d31d0* x) { return x->run(); }

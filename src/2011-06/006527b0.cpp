// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006527b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006527b0* base();
    X_006527b0* run() {
    f_0 = (void*)0xa9a2dc;
    f_4 = (void*)0xa9a2d4;
    f_18 = (void*)0xa9a2c8;
    f_1c = (void*)0xa9a2bc;
    f_90 = (void*)0xa9a294;
        return base();
    }
};
X_006527b0* func_006527b0(X_006527b0* x) { return x->run(); }

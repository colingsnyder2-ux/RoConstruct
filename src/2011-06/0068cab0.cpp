// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0068cab0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_0068cab0* base();
    X_0068cab0* run() {
    f_0 = (void*)0xa9f6fc;
    f_4 = (void*)0xa9f6f4;
    f_18 = (void*)0xa9f6e8;
    f_1c = (void*)0xa9f6dc;
    f_90 = (void*)0xa9f6d4;
        return base();
    }
};
X_0068cab0* func_0068cab0(X_0068cab0* x) { return x->run(); }

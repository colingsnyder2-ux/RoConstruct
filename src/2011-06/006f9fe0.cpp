// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f9fe0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006f9fe0* base();
    X_006f9fe0* run() {
    f_0 = (void*)0xaaab14;
    f_4 = (void*)0xaaab08;
    f_18 = (void*)0xaaaafc;
    f_1c = (void*)0xaaaaf0;
    f_90 = (void*)0xaaaac8;
        return base();
    }
};
X_006f9fe0* func_006f9fe0(X_006f9fe0* x) { return x->run(); }

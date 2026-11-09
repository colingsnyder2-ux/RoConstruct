// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f9fb0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006f9fb0* base();
    X_006f9fb0* run() {
    f_0 = (void*)0xaaabc4;
    f_4 = (void*)0xaaabb8;
    f_18 = (void*)0xaaabac;
    f_1c = (void*)0xaaaba0;
    f_90 = (void*)0xaaab78;
        return base();
    }
};
X_006f9fb0* func_006f9fb0(X_006f9fb0* x) { return x->run(); }

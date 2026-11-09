// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00691630 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00691630* base();
    X_00691630* run() {
    f_0 = (void*)0xaa0f0c;
    f_4 = (void*)0xaa0f04;
    f_18 = (void*)0xaa0ef8;
    f_1c = (void*)0xaa0eec;
        return base();
    }
};
X_00691630* func_00691630(X_00691630* x) { return x->run(); }

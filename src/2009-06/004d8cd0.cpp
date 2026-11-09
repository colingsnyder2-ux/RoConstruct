// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004d8cd0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_004d8cd0* base();
    X_004d8cd0* run() {
    f_0 = (void*)0x8c63ec;
    f_14 = (void*)0x8c63dc;
    f_18 = (void*)0x8c63d4;
    f_20 = (void*)0x8c63cc;
        return base();
    }
};
X_004d8cd0* func_004d8cd0(X_004d8cd0* x) { return x->run(); }

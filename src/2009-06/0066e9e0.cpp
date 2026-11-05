// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0066e9e0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0066e9e0* base();
    X_0066e9e0* run() {
    f_0 = (void*)0x8e33c4;
    f_14 = (void*)0x8e33b8;
    f_18 = (void*)0x8e33b0;
    f_20 = (void*)0x8e33a8;
        return base();
    }
};
X_0066e9e0* func_0066e9e0(X_0066e9e0* x) { return x->run(); }

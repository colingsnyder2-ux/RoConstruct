// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00624b60 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00624b60* base();
    X_00624b60* run() {
    f_0 = (void*)0x8d9a7c;
    f_14 = (void*)0x8d9a70;
    f_18 = (void*)0x8d9a68;
    f_20 = (void*)0x8d9a60;
        return base();
    }
};
X_00624b60* func_00624b60(X_00624b60* x) { return x->run(); }

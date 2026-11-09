// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0064c660 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0064c660* base();
    X_0064c660* run() {
    f_0 = (void*)0x8df214;
    f_14 = (void*)0x8df204;
    f_18 = (void*)0x8df1fc;
    f_20 = (void*)0x8df1f4;
        return base();
    }
};
X_0064c660* func_0064c660(X_0064c660* x) { return x->run(); }

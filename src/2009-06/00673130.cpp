// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00673130 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_00673130* base();
    X_00673130* run() {
    f_0 = (void*)0x8e3e04;
    f_14 = (void*)0x8e3df4;
    f_18 = (void*)0x8e3dec;
    f_20 = (void*)0x8e3de4;
    f_8c = (void*)0x8e3ddc;
        return base();
    }
};
X_00673130* func_00673130(X_00673130* x) { return x->run(); }

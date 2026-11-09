// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00625260 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_00625260* base();
    X_00625260* run() {
    f_0 = (void*)0x8d9ea4;
    f_14 = (void*)0x8d9e98;
    f_18 = (void*)0x8d9e90;
    f_20 = (void*)0x8d9e88;
    f_8c = (void*)0x8d9e80;
        return base();
    }
};
X_00625260* func_00625260(X_00625260* x) { return x->run(); }

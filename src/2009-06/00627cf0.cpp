// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00627cf0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_00627cf0* base();
    X_00627cf0* run() {
    f_0 = (void*)0x8da51c;
    f_14 = (void*)0x8da510;
    f_18 = (void*)0x8da508;
    f_20 = (void*)0x8da500;
    f_8c = (void*)0x8da4f8;
        return base();
    }
};
X_00627cf0* func_00627cf0(X_00627cf0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006733f0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    X_006733f0* base();
    X_006733f0* run() {
    f_0 = (void*)0x8e3ee4;
    f_14 = (void*)0x8e3ed8;
    f_18 = (void*)0x8e3ed0;
    f_20 = (void*)0x8e3ec8;
    f_8c = (void*)0x8e3ec0;
        return base();
    }
};
X_006733f0* func_006733f0(X_006733f0* x) { return x->run(); }

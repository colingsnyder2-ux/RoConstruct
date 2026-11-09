// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00692d80 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_00692d80* base();
    X_00692d80* run() {
    f_0 = (void*)0xaa14d4;
    f_4 = (void*)0xaa14cc;
    f_18 = (void*)0xaa14c0;
    f_1c = (void*)0xaa14b4;
    f_90 = (void*)0xaa14ac;
        return base();
    }
};
X_00692d80* func_00692d80(X_00692d80* x) { return x->run(); }

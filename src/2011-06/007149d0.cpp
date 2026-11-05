// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_007149d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_007149d0* base();
    X_007149d0* run() {
    f_0 = (void*)0xaaf76c;
    f_4 = (void*)0xaaf764;
    f_18 = (void*)0xaaf758;
    f_1c = (void*)0xaaf74c;
        return base();
    }
};
X_007149d0* func_007149d0(X_007149d0* x) { return x->run(); }

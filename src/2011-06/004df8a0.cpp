// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004df8a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_004df8a0* base();
    X_004df8a0* run() {
    f_0 = (void*)0xa7999c;
    f_4 = (void*)0xa79990;
    f_18 = (void*)0xa79984;
    f_1c = (void*)0xa79978;
    f_90 = (void*)0xa79934;
        return base();
    }
};
X_004df8a0* func_004df8a0(X_004df8a0* x) { return x->run(); }

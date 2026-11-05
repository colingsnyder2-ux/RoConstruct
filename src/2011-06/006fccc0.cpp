// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006fccc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006fccc0* base();
    X_006fccc0* run() {
    f_0 = (void*)0xaab844;
    f_4 = (void*)0xaab83c;
    f_18 = (void*)0xaab830;
    f_1c = (void*)0xaab824;
        return base();
    }
};
X_006fccc0* func_006fccc0(X_006fccc0* x) { return x->run(); }

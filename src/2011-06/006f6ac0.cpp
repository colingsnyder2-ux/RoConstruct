// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f6ac0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006f6ac0* base();
    X_006f6ac0* run() {
    f_0 = (void*)0xaaa17c;
    f_4 = (void*)0xaaa174;
    f_18 = (void*)0xaaa168;
    f_1c = (void*)0xaaa15c;
        return base();
    }
};
X_006f6ac0* func_006f6ac0(X_006f6ac0* x) { return x->run(); }

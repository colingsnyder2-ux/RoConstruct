// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00643f10 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00643f10* base();
    X_00643f10* run() {
    f_0 = (void*)0x8de534;
    f_14 = (void*)0x8de524;
    f_18 = (void*)0x8de51c;
    f_20 = (void*)0x8de514;
        return base();
    }
};
X_00643f10* func_00643f10(X_00643f10* x) { return x->run(); }

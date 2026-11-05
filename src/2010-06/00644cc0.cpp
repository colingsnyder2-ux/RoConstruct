// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00644cc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00644cc0* base();
    X_00644cc0* run() {
    f_0 = (void*)0xa3732c;
    f_4 = (void*)0xa37324;
    f_18 = (void*)0xa37318;
    f_1c = (void*)0xa3730c;
        return base();
    }
};
X_00644cc0* func_00644cc0(X_00644cc0* x) { return x->run(); }

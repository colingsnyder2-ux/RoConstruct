// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00631ab0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00631ab0* base();
    X_00631ab0* run() {
    f_0 = (void*)0xa35b7c;
    f_4 = (void*)0xa35b74;
    f_18 = (void*)0xa35b68;
    f_1c = (void*)0xa35b5c;
        return base();
    }
};
X_00631ab0* func_00631ab0(X_00631ab0* x) { return x->run(); }

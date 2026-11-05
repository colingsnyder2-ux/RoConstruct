// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00671900 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_00671900* base();
    X_00671900* run() {
    f_0 = (void*)0x8e3a14;
    f_14 = (void*)0x8e3a08;
    f_18 = (void*)0x8e3a00;
    f_20 = (void*)0x8e39f8;
        return base();
    }
};
X_00671900* func_00671900(X_00671900* x) { return x->run(); }

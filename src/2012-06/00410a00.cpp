// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00410a00 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00410a00* base();
    X_00410a00* run() {
    f_0 = (void*)0xb44574;
    f_4 = (void*)0xb4456c;
    f_18 = (void*)0xb44560;
    f_1c = (void*)0xb44554;
        return base();
    }
};
X_00410a00* func_00410a00(X_00410a00* x) { return x->run(); }

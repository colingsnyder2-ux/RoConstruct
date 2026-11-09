// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d3a90 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006d3a90* base();
    X_006d3a90* run() {
    f_0 = (void*)0xaa659c;
    f_4 = (void*)0xaa6594;
    f_18 = (void*)0xaa6588;
    f_1c = (void*)0xaa657c;
    f_90 = (void*)0xaa6554;
        return base();
    }
};
X_006d3a90* func_006d3a90(X_006d3a90* x) { return x->run(); }

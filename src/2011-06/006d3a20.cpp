// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d3a20 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006d3a20* base();
    X_006d3a20* run() {
    f_0 = (void*)0xaa64f4;
    f_4 = (void*)0xaa64ec;
    f_18 = (void*)0xaa64e0;
    f_1c = (void*)0xaa64d4;
    f_90 = (void*)0xaa64ac;
        return base();
    }
};
X_006d3a20* func_006d3a20(X_006d3a20* x) { return x->run(); }

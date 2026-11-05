// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006d3b50 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_006d3b50* base();
    X_006d3b50* run() {
    f_0 = (void*)0xaa6254;
    f_4 = (void*)0xaa624c;
    f_18 = (void*)0xaa6240;
    f_1c = (void*)0xaa6234;
    f_90 = (void*)0xaa620c;
        return base();
    }
};
X_006d3b50* func_006d3b50(X_006d3b50* x) { return x->run(); }

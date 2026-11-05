// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00633db0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_00633db0* base();
    X_00633db0* run() {
    f_0 = (void*)0xa96804;
    f_4 = (void*)0xa967f8;
    f_18 = (void*)0xa967ec;
    f_1c = (void*)0xa967e0;
    f_90 = (void*)0xa967d8;
        return base();
    }
};
X_00633db0* func_00633db0(X_00633db0* x) { return x->run(); }

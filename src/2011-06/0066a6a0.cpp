// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0066a6a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_0066a6a0* base();
    X_0066a6a0* run() {
    f_0 = (void*)0xa9c554;
    f_4 = (void*)0xa9c548;
    f_18 = (void*)0xa9c53c;
    f_1c = (void*)0xa9c530;
    f_90 = (void*)0xa9c524;
        return base();
    }
};
X_0066a6a0* func_0066a6a0(X_0066a6a0* x) { return x->run(); }

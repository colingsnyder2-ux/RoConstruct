// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0066a640 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_0066a640* base();
    X_0066a640* run() {
    f_0 = (void*)0xa9c4c4;
    f_4 = (void*)0xa9c4b8;
    f_18 = (void*)0xa9c4ac;
    f_1c = (void*)0xa9c4a0;
    f_90 = (void*)0xa9c494;
        return base();
    }
};
X_0066a640* func_0066a640(X_0066a640* x) { return x->run(); }

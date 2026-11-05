// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0065e120 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0065e120* base();
    X_0065e120* run() {
    f_0 = (void*)0xa9b41c;
    f_4 = (void*)0xa9b414;
    f_18 = (void*)0xa9b408;
    f_1c = (void*)0xa9b3fc;
        return base();
    }
};
X_0065e120* func_0065e120(X_0065e120* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0066ac70 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0066ac70* base();
    X_0066ac70* run() {
    f_0 = (void*)0xa3c3dc;
    f_4 = (void*)0xa3c3d4;
    f_18 = (void*)0xa3c3c8;
    f_1c = (void*)0xa3c3bc;
        return base();
    }
};
X_0066ac70* func_0066ac70(X_0066ac70* x) { return x->run(); }

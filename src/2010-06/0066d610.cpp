// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0066d610 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0066d610* base();
    X_0066d610* run() {
    f_0 = (void*)0xa3c764;
    f_4 = (void*)0xa3c758;
    f_18 = (void*)0xa3c74c;
    f_1c = (void*)0xa3c740;
        return base();
    }
};
X_0066d610* func_0066d610(X_0066d610* x) { return x->run(); }

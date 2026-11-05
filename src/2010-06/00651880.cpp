// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00651880 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00651880* base();
    X_00651880* run() {
    f_0 = (void*)0xa394e4;
    f_4 = (void*)0xa394dc;
    f_18 = (void*)0xa394d0;
    f_1c = (void*)0xa394c4;
        return base();
    }
};
X_00651880* func_00651880(X_00651880* x) { return x->run(); }

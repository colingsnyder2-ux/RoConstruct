// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00673bc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00673bc0* base();
    X_00673bc0* run() {
    f_0 = (void*)0xa9d11c;
    f_4 = (void*)0xa9d114;
    f_18 = (void*)0xa9d108;
    f_1c = (void*)0xa9d0fc;
        return base();
    }
};
X_00673bc0* func_00673bc0(X_00673bc0* x) { return x->run(); }

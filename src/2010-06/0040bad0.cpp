// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040bad0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040bad0* base();
    X_0040bad0* run() {
    f_0 = (void*)0xa00f5c;
    f_4 = (void*)0xa00f50;
    f_18 = (void*)0xa00f44;
    f_1c = (void*)0xa00f38;
        return base();
    }
};
X_0040bad0* func_0040bad0(X_0040bad0* x) { return x->run(); }

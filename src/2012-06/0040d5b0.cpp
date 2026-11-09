// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040d5b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040d5b0* base();
    X_0040d5b0* run() {
    f_0 = (void*)0xb43fec;
    f_4 = (void*)0xb43fe4;
    f_18 = (void*)0xb43fd8;
    f_1c = (void*)0xb43fcc;
        return base();
    }
};
X_0040d5b0* func_0040d5b0(X_0040d5b0* x) { return x->run(); }

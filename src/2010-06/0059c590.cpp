// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0059c590 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0059c590* base();
    X_0059c590* run() {
    f_0 = (void*)0xa2a124;
    f_4 = (void*)0xa2a118;
    f_18 = (void*)0xa2a10c;
    f_1c = (void*)0xa2a100;
        return base();
    }
};
X_0059c590* func_0059c590(X_0059c590* x) { return x->run(); }

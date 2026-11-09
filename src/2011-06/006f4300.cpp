// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f4300 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006f4300* base();
    X_006f4300* run() {
    f_0 = (void*)0xaa985c;
    f_4 = (void*)0xaa9854;
    f_18 = (void*)0xaa9848;
    f_1c = (void*)0xaa983c;
        return base();
    }
};
X_006f4300* func_006f4300(X_006f4300* x) { return x->run(); }

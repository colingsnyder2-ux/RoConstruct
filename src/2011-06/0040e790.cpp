// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0040e790 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0040e790* base();
    X_0040e790* run() {
    f_0 = (void*)0xa5c46c;
    f_4 = (void*)0xa5c460;
    f_18 = (void*)0xa5c454;
    f_1c = (void*)0xa5c448;
        return base();
    }
};
X_0040e790* func_0040e790(X_0040e790* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006f0a40 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006f0a40* base();
    X_006f0a40* run() {
    f_0 = (void*)0xaa911c;
    f_4 = (void*)0xaa9110;
    f_18 = (void*)0xaa9104;
    f_1c = (void*)0xaa90f8;
        return base();
    }
};
X_006f0a40* func_006f0a40(X_006f0a40* x) { return x->run(); }

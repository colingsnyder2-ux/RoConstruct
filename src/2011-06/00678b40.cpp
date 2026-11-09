// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00678b40 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00678b40* base();
    X_00678b40* run() {
    f_0 = (void*)0xa9d74c;
    f_4 = (void*)0xa9d744;
    f_18 = (void*)0xa9d738;
    f_1c = (void*)0xa9d72c;
        return base();
    }
};
X_00678b40* func_00678b40(X_00678b40* x) { return x->run(); }

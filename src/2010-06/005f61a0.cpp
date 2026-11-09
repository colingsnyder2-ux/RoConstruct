// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_005f61a0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_005f61a0* base();
    X_005f61a0* run() {
    f_0 = (void*)0xa2f59c;
    f_4 = (void*)0xa2f590;
    f_18 = (void*)0xa2f584;
    f_1c = (void*)0xa2f578;
    f_94 = (void*)0xa2f570;
        return base();
    }
};
X_005f61a0* func_005f61a0(X_005f61a0* x) { return x->run(); }

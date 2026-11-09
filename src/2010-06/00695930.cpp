// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00695930 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    X_00695930* base();
    X_00695930* run() {
    f_0 = (void*)0xa3e63c;
    f_4 = (void*)0xa3e634;
    f_18 = (void*)0xa3e628;
    f_1c = (void*)0xa3e61c;
    f_94 = (void*)0xa3e604;
        return base();
    }
};
X_00695930* func_00695930(X_00695930* x) { return x->run(); }

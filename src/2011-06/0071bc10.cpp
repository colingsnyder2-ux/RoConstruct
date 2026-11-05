// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0071bc10 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0071bc10* base();
    X_0071bc10* run() {
    f_0 = (void*)0xab137c;
    f_4 = (void*)0xab1374;
    f_18 = (void*)0xab1368;
    f_1c = (void*)0xab135c;
        return base();
    }
};
X_0071bc10* func_0071bc10(X_0071bc10* x) { return x->run(); }

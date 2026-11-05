// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004b1490 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_004b1490* base();
    X_004b1490* run() {
    f_0 = (void*)0xa7736c;
    f_4 = (void*)0xa77360;
    f_18 = (void*)0xa77354;
    f_1c = (void*)0xa77348;
        return base();
    }
};
X_004b1490* func_004b1490(X_004b1490* x) { return x->run(); }

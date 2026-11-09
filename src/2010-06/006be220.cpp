// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006be220 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006be220* base();
    X_006be220* run() {
    f_0 = (void*)0xa434b4;
    f_4 = (void*)0xa434ac;
    f_18 = (void*)0xa434a0;
    f_1c = (void*)0xa43494;
        return base();
    }
};
X_006be220* func_006be220(X_006be220* x) { return x->run(); }

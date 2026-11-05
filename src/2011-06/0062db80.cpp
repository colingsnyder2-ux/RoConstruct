// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0062db80 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_0062db80* base();
    X_0062db80* run() {
    f_0 = (void*)0xa95904;
    f_4 = (void*)0xa958fc;
    f_18 = (void*)0xa958f0;
    f_1c = (void*)0xa958e4;
    f_90 = (void*)0xa958dc;
        return base();
    }
};
X_0062db80* func_0062db80(X_0062db80* x) { return x->run(); }

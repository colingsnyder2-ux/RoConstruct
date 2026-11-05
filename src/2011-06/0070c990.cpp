// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0070c990 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0070c990* base();
    X_0070c990* run() {
    f_0 = (void*)0xaae29c;
    f_4 = (void*)0xaae294;
    f_18 = (void*)0xaae288;
    f_1c = (void*)0xaae27c;
        return base();
    }
};
X_0070c990* func_0070c990(X_0070c990* x) { return x->run(); }

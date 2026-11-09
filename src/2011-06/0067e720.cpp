// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0067e720 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0067e720* base();
    X_0067e720* run() {
    f_0 = (void*)0xa9e64c;
    f_4 = (void*)0xa9e640;
    f_18 = (void*)0xa9e634;
    f_1c = (void*)0xa9e628;
        return base();
    }
};
X_0067e720* func_0067e720(X_0067e720* x) { return x->run(); }

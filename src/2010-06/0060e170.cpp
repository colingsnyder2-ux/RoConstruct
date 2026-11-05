// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0060e170 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0060e170* base();
    X_0060e170* run() {
    f_0 = (void*)0xa314a4;
    f_4 = (void*)0xa3149c;
    f_18 = (void*)0xa31490;
    f_1c = (void*)0xa31484;
        return base();
    }
};
X_0060e170* func_0060e170(X_0060e170* x) { return x->run(); }

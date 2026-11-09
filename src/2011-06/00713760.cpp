// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00713760 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00713760* base();
    X_00713760* run() {
    f_0 = (void*)0xaaf0d4;
    f_4 = (void*)0xaaf0cc;
    f_18 = (void*)0xaaf0c0;
    f_1c = (void*)0xaaf0b4;
        return base();
    }
};
X_00713760* func_00713760(X_00713760* x) { return x->run(); }

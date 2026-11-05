// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00712dc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_00712dc0* base();
    X_00712dc0* run() {
    f_0 = (void*)0xaaef44;
    f_4 = (void*)0xaaef3c;
    f_18 = (void*)0xaaef30;
    f_1c = (void*)0xaaef24;
    f_90 = (void*)0xaaef18;
        return base();
    }
};
X_00712dc0* func_00712dc0(X_00712dc0* x) { return x->run(); }

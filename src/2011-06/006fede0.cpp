// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006fede0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006fede0* base();
    X_006fede0* run() {
    f_0 = (void*)0xaabec4;
    f_4 = (void*)0xaabebc;
    f_18 = (void*)0xaabeb0;
    f_1c = (void*)0xaabea4;
        return base();
    }
};
X_006fede0* func_006fede0(X_006fede0* x) { return x->run(); }

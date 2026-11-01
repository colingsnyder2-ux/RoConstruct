// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00411ea0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_00411ea0* base();
    X_00411ea0* run() {
    f_0 = (void*)0xb4487c;
    f_4 = (void*)0xb44874;
    f_18 = (void*)0xb44868;
    f_1c = (void*)0xb4485c;
        return base();
    }
};
X_00411ea0* func_00411ea0(X_00411ea0* x) { return x->run(); }

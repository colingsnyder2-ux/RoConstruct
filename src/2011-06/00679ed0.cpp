// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00679ed0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_00679ed0* base();
    X_00679ed0* run() {
    f_0 = (void*)0xa9dba4;
    f_4 = (void*)0xa9db98;
    f_18 = (void*)0xa9db8c;
    f_1c = (void*)0xa9db80;
    f_90 = (void*)0xa9db78;
        return base();
    }
};
X_00679ed0* func_00679ed0(X_00679ed0* x) { return x->run(); }

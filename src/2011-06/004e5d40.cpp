// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_004e5d40 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_004e5d40* base();
    X_004e5d40* run() {
    f_0 = (void*)0xa7a67c;
    f_4 = (void*)0xa7a670;
    f_18 = (void*)0xa7a664;
    f_1c = (void*)0xa7a658;
    f_90 = (void*)0xa7a630;
        return base();
    }
};
X_004e5d40* func_004e5d40(X_004e5d40* x) { return x->run(); }

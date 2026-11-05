// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_007a40b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    X_007a40b0* base();
    X_007a40b0* run() {
    f_0 = (void*)0xbb53cc;
    f_4 = (void*)0xbb53c0;
    f_18 = (void*)0xbb53b4;
    f_1c = (void*)0xbb53a8;
    f_80 = (void*)0xbb539c;
        return base();
    }
};
X_007a40b0* func_007a40b0(X_007a40b0* x) { return x->run(); }

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_00821780 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    X_00821780* base();
    X_00821780* run() {
    f_0 = (void*)0xbcbcfc;
    f_4 = (void*)0xbcbcf4;
    f_18 = (void*)0xbcbce8;
    f_1c = (void*)0xbcbcdc;
    f_80 = (void*)0xbcbcd4;
        return base();
    }
};
X_00821780* func_00821780(X_00821780* x) { return x->run(); }

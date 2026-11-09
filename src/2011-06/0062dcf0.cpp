// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0062dcf0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    X_0062dcf0* base();
    X_0062dcf0* run() {
    f_0 = (void*)0xa959b4;
    f_4 = (void*)0xa959a8;
    f_18 = (void*)0xa9599c;
    f_1c = (void*)0xa95990;
    f_90 = (void*)0xa95988;
        return base();
    }
};
X_0062dcf0* func_0062dcf0(X_0062dcf0* x) { return x->run(); }

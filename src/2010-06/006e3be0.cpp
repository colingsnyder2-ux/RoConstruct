// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_006e3be0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_006e3be0* base();
    X_006e3be0* run() {
    f_0 = (void*)0xa4915c;
    f_4 = (void*)0xa49154;
    f_18 = (void*)0xa49148;
    f_1c = (void*)0xa4913c;
        return base();
    }
};
X_006e3be0* func_006e3be0(X_006e3be0* x) { return x->run(); }

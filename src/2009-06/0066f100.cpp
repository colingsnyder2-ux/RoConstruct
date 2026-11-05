// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0066f100 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    X_0066f100* base();
    X_0066f100* run() {
    f_0 = (void*)0x8e3524;
    f_14 = (void*)0x8e3518;
    f_18 = (void*)0x8e3510;
    f_20 = (void*)0x8e3508;
        return base();
    }
};
X_0066f100* func_0066f100(X_0066f100* x) { return x->run(); }

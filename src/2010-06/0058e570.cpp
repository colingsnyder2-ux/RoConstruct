// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct X_0058e570 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    X_0058e570* base();
    X_0058e570* run() {
    f_0 = (void*)0xa28cec;
    f_4 = (void*)0xa28ce4;
    f_18 = (void*)0xa28cd8;
    f_1c = (void*)0xa28ccc;
        return base();
    }
};
X_0058e570* func_0058e570(X_0058e570* x) { return x->run(); }

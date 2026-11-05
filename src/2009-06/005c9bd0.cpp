// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern void* g_singleton_005c9bd0;
struct X_005c9bd0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    void base();
    void run() {
        g_singleton_005c9bd0 = 0;
        f_0 = (void*)0x8d43c4;
        f_14 = (void*)0x8d43b4;
        f_18 = (void*)0x8d43ac;
        f_20 = (void*)0x8d43a4;
        base();
    }
};
void func_005c9bd0(X_005c9bd0* x) { x->run(); }

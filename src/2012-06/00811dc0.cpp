// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00811dc0, g_4_00811dc0, g_18_00811dc0, g_1c_00811dc0, g_80_00811dc0;
extern "C" void cleanup_00811dc0(void*);
struct X_00811dc0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_00811dc0* init(int flags);
};
X_00811dc0* X_00811dc0::init(int flags) {
    f_0 = &g_0_00811dc0;
    f_4 = &g_4_00811dc0;
    f_18 = &g_18_00811dc0;
    f_1c = &g_1c_00811dc0;
    f_80 = &g_80_00811dc0;
    base();
    if (flags & 1) cleanup_00811dc0(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00811d20, g_4_00811d20, g_18_00811d20, g_1c_00811d20, g_80_00811d20;
extern "C" void cleanup_00811d20(void*);
struct X_00811d20 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_00811d20* init(int flags);
};
X_00811d20* X_00811d20::init(int flags) {
    f_0 = &g_0_00811d20;
    f_4 = &g_4_00811d20;
    f_18 = &g_18_00811d20;
    f_1c = &g_1c_00811d20;
    f_80 = &g_80_00811d20;
    base();
    if (flags & 1) cleanup_00811d20(this);
    return this;
}

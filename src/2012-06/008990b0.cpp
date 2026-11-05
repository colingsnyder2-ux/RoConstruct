// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_008990b0, g_4_008990b0, g_18_008990b0, g_1c_008990b0, g_80_008990b0;
extern "C" void cleanup_008990b0(void*);
struct X_008990b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_008990b0* init(int flags);
};
X_008990b0* X_008990b0::init(int flags) {
    f_0 = &g_0_008990b0;
    f_4 = &g_4_008990b0;
    f_18 = &g_18_008990b0;
    f_1c = &g_1c_008990b0;
    f_80 = &g_80_008990b0;
    base();
    if (flags & 1) cleanup_008990b0(this);
    return this;
}

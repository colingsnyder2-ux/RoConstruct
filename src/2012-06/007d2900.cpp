// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_007d2900, g_4_007d2900, g_18_007d2900, g_1c_007d2900, g_80_007d2900;
extern "C" void cleanup_007d2900(void*);
struct X_007d2900 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_007d2900* init(int flags);
};
X_007d2900* X_007d2900::init(int flags) {
    f_0 = &g_0_007d2900;
    f_4 = &g_4_007d2900;
    f_18 = &g_18_007d2900;
    f_1c = &g_1c_007d2900;
    f_80 = &g_80_007d2900;
    base();
    if (flags & 1) cleanup_007d2900(this);
    return this;
}

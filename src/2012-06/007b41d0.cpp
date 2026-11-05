// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_007b41d0, g_4_007b41d0, g_18_007b41d0, g_1c_007b41d0, g_80_007b41d0;
extern "C" void cleanup_007b41d0(void*);
struct X_007b41d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_007b41d0* init(int flags);
};
X_007b41d0* X_007b41d0::init(int flags) {
    f_0 = &g_0_007b41d0;
    f_4 = &g_4_007b41d0;
    f_18 = &g_18_007b41d0;
    f_1c = &g_1c_007b41d0;
    f_80 = &g_80_007b41d0;
    base();
    if (flags & 1) cleanup_007b41d0(this);
    return this;
}

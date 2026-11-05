// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00628f20, g_4_00628f20, g_18_00628f20, g_1c_00628f20, g_94_00628f20;
extern "C" void cleanup_00628f20(void*);
struct X_00628f20 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_00628f20* init(int flags);
};
X_00628f20* X_00628f20::init(int flags) {
    f_0 = &g_0_00628f20;
    f_4 = &g_4_00628f20;
    f_18 = &g_18_00628f20;
    f_1c = &g_1c_00628f20;
    f_94 = &g_94_00628f20;
    base();
    if (flags & 1) cleanup_00628f20(this);
    return this;
}

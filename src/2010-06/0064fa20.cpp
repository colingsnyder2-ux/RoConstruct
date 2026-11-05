// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0064fa20, g_4_0064fa20, g_18_0064fa20, g_1c_0064fa20, g_94_0064fa20;
extern "C" void cleanup_0064fa20(void*);
struct X_0064fa20 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_0064fa20* init(int flags);
};
X_0064fa20* X_0064fa20::init(int flags) {
    f_0 = &g_0_0064fa20;
    f_4 = &g_4_0064fa20;
    f_18 = &g_18_0064fa20;
    f_1c = &g_1c_0064fa20;
    f_94 = &g_94_0064fa20;
    base();
    if (flags & 1) cleanup_0064fa20(this);
    return this;
}

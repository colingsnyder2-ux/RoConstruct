// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0064a810, g_14_0064a810, g_18_0064a810, g_20_0064a810, g_8c_0064a810;
extern "C" void cleanup_0064a810(void*);
struct X_0064a810 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_0064a810* init(int flags);
};
X_0064a810* X_0064a810::init(int flags) {
    f_0 = &g_0_0064a810;
    f_14 = &g_14_0064a810;
    f_18 = &g_18_0064a810;
    f_20 = &g_20_0064a810;
    f_8c = &g_8c_0064a810;
    base();
    if (flags & 1) cleanup_0064a810(this);
    return this;
}

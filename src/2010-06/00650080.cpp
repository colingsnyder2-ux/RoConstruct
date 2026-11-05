// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00650080, g_4_00650080, g_18_00650080, g_1c_00650080, g_94_00650080;
extern "C" void cleanup_00650080(void*);
struct X_00650080 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_00650080* init(int flags);
};
X_00650080* X_00650080::init(int flags) {
    f_0 = &g_0_00650080;
    f_4 = &g_4_00650080;
    f_18 = &g_18_00650080;
    f_1c = &g_1c_00650080;
    f_94 = &g_94_00650080;
    base();
    if (flags & 1) cleanup_00650080(this);
    return this;
}

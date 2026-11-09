// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_005fbe40, g_4_005fbe40, g_18_005fbe40, g_1c_005fbe40, g_94_005fbe40;
extern "C" void cleanup_005fbe40(void*);
struct X_005fbe40 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_005fbe40* init(int flags);
};
X_005fbe40* X_005fbe40::init(int flags) {
    f_0 = &g_0_005fbe40;
    f_4 = &g_4_005fbe40;
    f_18 = &g_18_005fbe40;
    f_1c = &g_1c_005fbe40;
    f_94 = &g_94_005fbe40;
    base();
    if (flags & 1) cleanup_005fbe40(this);
    return this;
}

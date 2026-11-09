// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00696100, g_4_00696100, g_18_00696100, g_1c_00696100, g_94_00696100;
extern "C" void cleanup_00696100(void*);
struct X_00696100 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_00696100* init(int flags);
};
X_00696100* X_00696100::init(int flags) {
    f_0 = &g_0_00696100;
    f_4 = &g_4_00696100;
    f_18 = &g_18_00696100;
    f_1c = &g_1c_00696100;
    f_94 = &g_94_00696100;
    base();
    if (flags & 1) cleanup_00696100(this);
    return this;
}

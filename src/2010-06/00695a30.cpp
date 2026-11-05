// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00695a30, g_4_00695a30, g_18_00695a30, g_1c_00695a30, g_94_00695a30;
extern "C" void cleanup_00695a30(void*);
struct X_00695a30 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_00695a30* init(int flags);
};
X_00695a30* X_00695a30::init(int flags) {
    f_0 = &g_0_00695a30;
    f_4 = &g_4_00695a30;
    f_18 = &g_18_00695a30;
    f_1c = &g_1c_00695a30;
    f_94 = &g_94_00695a30;
    base();
    if (flags & 1) cleanup_00695a30(this);
    return this;
}

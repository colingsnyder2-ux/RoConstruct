// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0076f620, g_4_0076f620, g_18_0076f620, g_1c_0076f620, g_94_0076f620;
extern "C" void cleanup_0076f620(void*);
struct X_0076f620 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_0076f620* init(int flags);
};
X_0076f620* X_0076f620::init(int flags) {
    f_0 = &g_0_0076f620;
    f_4 = &g_4_0076f620;
    f_18 = &g_18_0076f620;
    f_1c = &g_1c_0076f620;
    f_94 = &g_94_0076f620;
    base();
    if (flags & 1) cleanup_0076f620(this);
    return this;
}

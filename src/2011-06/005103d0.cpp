// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_005103d0, g_4_005103d0, g_18_005103d0, g_1c_005103d0, g_10cc_005103d0;
extern "C" void cleanup_005103d0(void*);
struct X_005103d0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[4268];
    void* f_10cc;
    void base();
    X_005103d0* init(int flags);
};
X_005103d0* X_005103d0::init(int flags) {
    f_0 = &g_0_005103d0;
    f_4 = &g_4_005103d0;
    f_18 = &g_18_005103d0;
    f_1c = &g_1c_005103d0;
    f_10cc = &g_10cc_005103d0;
    base();
    if (flags & 1) cleanup_005103d0(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00693300, g_4_00693300, g_18_00693300, g_1c_00693300, g_90_00693300;
extern "C" void cleanup_00693300(void*);
struct X_00693300 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_00693300* init(int flags);
};
X_00693300* X_00693300::init(int flags) {
    f_0 = &g_0_00693300;
    f_4 = &g_4_00693300;
    f_18 = &g_18_00693300;
    f_1c = &g_1c_00693300;
    f_90 = &g_90_00693300;
    base();
    if (flags & 1) cleanup_00693300(this);
    return this;
}

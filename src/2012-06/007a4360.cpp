// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_007a4360, g_4_007a4360, g_18_007a4360, g_1c_007a4360, g_80_007a4360;
extern "C" void cleanup_007a4360(void*);
struct X_007a4360 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_007a4360* init(int flags);
};
X_007a4360* X_007a4360::init(int flags) {
    f_0 = &g_0_007a4360;
    f_4 = &g_4_007a4360;
    f_18 = &g_18_007a4360;
    f_1c = &g_1c_007a4360;
    f_80 = &g_80_007a4360;
    base();
    if (flags & 1) cleanup_007a4360(this);
    return this;
}

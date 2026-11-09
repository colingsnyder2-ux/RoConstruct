// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_007d1380, g_4_007d1380, g_18_007d1380, g_1c_007d1380, g_80_007d1380;
extern "C" void cleanup_007d1380(void*);
struct X_007d1380 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_007d1380* init(int flags);
};
X_007d1380* X_007d1380::init(int flags) {
    f_0 = &g_0_007d1380;
    f_4 = &g_4_007d1380;
    f_18 = &g_18_007d1380;
    f_1c = &g_1c_007d1380;
    f_80 = &g_80_007d1380;
    base();
    if (flags & 1) cleanup_007d1380(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_007ce700, g_4_007ce700, g_18_007ce700, g_1c_007ce700, g_80_007ce700;
extern "C" void cleanup_007ce700(void*);
struct X_007ce700 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_007ce700* init(int flags);
};
X_007ce700* X_007ce700::init(int flags) {
    f_0 = &g_0_007ce700;
    f_4 = &g_4_007ce700;
    f_18 = &g_18_007ce700;
    f_1c = &g_1c_007ce700;
    f_80 = &g_80_007ce700;
    base();
    if (flags & 1) cleanup_007ce700(this);
    return this;
}

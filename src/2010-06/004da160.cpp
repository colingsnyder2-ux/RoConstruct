// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_004da160, g_4_004da160, g_18_004da160, g_1c_004da160, g_94_004da160;
extern "C" void cleanup_004da160(void*);
struct X_004da160 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_004da160* init(int flags);
};
X_004da160* X_004da160::init(int flags) {
    f_0 = &g_0_004da160;
    f_4 = &g_4_004da160;
    f_18 = &g_18_004da160;
    f_1c = &g_1c_004da160;
    f_94 = &g_94_004da160;
    base();
    if (flags & 1) cleanup_004da160(this);
    return this;
}

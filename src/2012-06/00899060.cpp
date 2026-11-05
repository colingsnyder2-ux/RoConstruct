// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00899060, g_4_00899060, g_18_00899060, g_1c_00899060, g_80_00899060;
extern "C" void cleanup_00899060(void*);
struct X_00899060 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_00899060* init(int flags);
};
X_00899060* X_00899060::init(int flags) {
    f_0 = &g_0_00899060;
    f_4 = &g_4_00899060;
    f_18 = &g_18_00899060;
    f_1c = &g_1c_00899060;
    f_80 = &g_80_00899060;
    base();
    if (flags & 1) cleanup_00899060(this);
    return this;
}

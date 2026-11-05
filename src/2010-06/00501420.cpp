// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00501420, g_4_00501420, g_18_00501420, g_1c_00501420, g_1ce0_00501420;
extern "C" void cleanup_00501420(void*);
struct X_00501420 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[7360];
    void* f_1ce0;
    void base();
    X_00501420* init(int flags);
};
X_00501420* X_00501420::init(int flags) {
    f_0 = &g_0_00501420;
    f_4 = &g_4_00501420;
    f_18 = &g_18_00501420;
    f_1c = &g_1c_00501420;
    f_1ce0 = &g_1ce0_00501420;
    base();
    if (flags & 1) cleanup_00501420(this);
    return this;
}

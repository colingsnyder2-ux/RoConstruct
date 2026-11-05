// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_006d32f0, g_4_006d32f0, g_18_006d32f0, g_1c_006d32f0, g_90_006d32f0;
extern "C" void cleanup_006d32f0(void*);
struct X_006d32f0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_006d32f0* init(int flags);
};
X_006d32f0* X_006d32f0::init(int flags) {
    f_0 = &g_0_006d32f0;
    f_4 = &g_4_006d32f0;
    f_18 = &g_18_006d32f0;
    f_1c = &g_1c_006d32f0;
    f_90 = &g_90_006d32f0;
    base();
    if (flags & 1) cleanup_006d32f0(this);
    return this;
}

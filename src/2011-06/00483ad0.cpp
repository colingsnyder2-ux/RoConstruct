// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00483ad0, g_4_00483ad0, g_18_00483ad0, g_1c_00483ad0, g_90_00483ad0;
extern "C" void cleanup_00483ad0(void*);
struct X_00483ad0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_00483ad0* init(int flags);
};
X_00483ad0* X_00483ad0::init(int flags) {
    f_0 = &g_0_00483ad0;
    f_4 = &g_4_00483ad0;
    f_18 = &g_18_00483ad0;
    f_1c = &g_1c_00483ad0;
    f_90 = &g_90_00483ad0;
    base();
    if (flags & 1) cleanup_00483ad0(this);
    return this;
}

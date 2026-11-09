// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00633ae0, g_4_00633ae0, g_18_00633ae0, g_1c_00633ae0, g_90_00633ae0;
extern "C" void cleanup_00633ae0(void*);
struct X_00633ae0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_00633ae0* init(int flags);
};
X_00633ae0* X_00633ae0::init(int flags) {
    f_0 = &g_0_00633ae0;
    f_4 = &g_4_00633ae0;
    f_18 = &g_18_00633ae0;
    f_1c = &g_1c_00633ae0;
    f_90 = &g_90_00633ae0;
    base();
    if (flags & 1) cleanup_00633ae0(this);
    return this;
}

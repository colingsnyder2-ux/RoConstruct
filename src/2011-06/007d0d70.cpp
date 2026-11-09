// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_007d0d70, g_4_007d0d70, g_18_007d0d70, g_1c_007d0d70, g_90_007d0d70;
extern "C" void cleanup_007d0d70(void*);
struct X_007d0d70 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_007d0d70* init(int flags);
};
X_007d0d70* X_007d0d70::init(int flags) {
    f_0 = &g_0_007d0d70;
    f_4 = &g_4_007d0d70;
    f_18 = &g_18_007d0d70;
    f_1c = &g_1c_007d0d70;
    f_90 = &g_90_007d0d70;
    base();
    if (flags & 1) cleanup_007d0d70(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00712d50, g_4_00712d50, g_18_00712d50, g_1c_00712d50, g_90_00712d50;
extern "C" void cleanup_00712d50(void*);
struct X_00712d50 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_00712d50* init(int flags);
};
X_00712d50* X_00712d50::init(int flags) {
    f_0 = &g_0_00712d50;
    f_4 = &g_4_00712d50;
    f_18 = &g_18_00712d50;
    f_1c = &g_1c_00712d50;
    f_90 = &g_90_00712d50;
    base();
    if (flags & 1) cleanup_00712d50(this);
    return this;
}

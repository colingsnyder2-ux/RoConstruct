// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00673160, g_14_00673160, g_18_00673160, g_20_00673160, g_8c_00673160;
extern "C" void cleanup_00673160(void*);
struct X_00673160 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_00673160* init(int flags);
};
X_00673160* X_00673160::init(int flags) {
    f_0 = &g_0_00673160;
    f_14 = &g_14_00673160;
    f_18 = &g_18_00673160;
    f_20 = &g_20_00673160;
    f_8c = &g_8c_00673160;
    base();
    if (flags & 1) cleanup_00673160(this);
    return this;
}

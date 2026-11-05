// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_005f2440, g_14_005f2440, g_18_005f2440, g_20_005f2440, g_8c_005f2440;
extern "C" void cleanup_005f2440(void*);
struct X_005f2440 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_005f2440* init(int flags);
};
X_005f2440* X_005f2440::init(int flags) {
    f_0 = &g_0_005f2440;
    f_14 = &g_14_005f2440;
    f_18 = &g_18_005f2440;
    f_20 = &g_20_005f2440;
    f_8c = &g_8c_005f2440;
    base();
    if (flags & 1) cleanup_005f2440(this);
    return this;
}

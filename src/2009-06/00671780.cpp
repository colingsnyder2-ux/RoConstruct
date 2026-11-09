// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00671780, g_14_00671780, g_18_00671780, g_20_00671780, g_8c_00671780;
extern "C" void cleanup_00671780(void*);
struct X_00671780 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_00671780* init(int flags);
};
X_00671780* X_00671780::init(int flags) {
    f_0 = &g_0_00671780;
    f_14 = &g_14_00671780;
    f_18 = &g_18_00671780;
    f_20 = &g_20_00671780;
    f_8c = &g_8c_00671780;
    base();
    if (flags & 1) cleanup_00671780(this);
    return this;
}

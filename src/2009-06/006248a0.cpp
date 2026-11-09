// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_006248a0, g_14_006248a0, g_18_006248a0, g_20_006248a0, g_8c_006248a0;
extern "C" void cleanup_006248a0(void*);
struct X_006248a0 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_006248a0* init(int flags);
};
X_006248a0* X_006248a0::init(int flags) {
    f_0 = &g_0_006248a0;
    f_14 = &g_14_006248a0;
    f_18 = &g_18_006248a0;
    f_20 = &g_20_006248a0;
    f_8c = &g_8c_006248a0;
    base();
    if (flags & 1) cleanup_006248a0(this);
    return this;
}

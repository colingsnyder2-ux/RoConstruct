// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0070a8b0, g_4_0070a8b0, g_18_0070a8b0, g_1c_0070a8b0, g_94_0070a8b0;
extern "C" void cleanup_0070a8b0(void*);
struct X_0070a8b0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_0070a8b0* init(int flags);
};
X_0070a8b0* X_0070a8b0::init(int flags) {
    f_0 = &g_0_0070a8b0;
    f_4 = &g_4_0070a8b0;
    f_18 = &g_18_0070a8b0;
    f_1c = &g_1c_0070a8b0;
    f_94 = &g_94_0070a8b0;
    base();
    if (flags & 1) cleanup_0070a8b0(this);
    return this;
}

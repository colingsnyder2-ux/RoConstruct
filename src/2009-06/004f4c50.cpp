// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_004f4c50, g_14_004f4c50, g_18_004f4c50, g_20_004f4c50, g_2ad8_004f4c50;
extern "C" void cleanup_004f4c50(void*);
struct X_004f4c50 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[10932];
    void* f_2ad8;
    void base();
    X_004f4c50* init(int flags);
};
X_004f4c50* X_004f4c50::init(int flags) {
    f_0 = &g_0_004f4c50;
    f_14 = &g_14_004f4c50;
    f_18 = &g_18_004f4c50;
    f_20 = &g_20_004f4c50;
    f_2ad8 = &g_2ad8_004f4c50;
    base();
    if (flags & 1) cleanup_004f4c50(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00629490, g_14_00629490, g_18_00629490, g_20_00629490, g_8c_00629490;
extern "C" void cleanup_00629490(void*);
struct X_00629490 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_00629490* init(int flags);
};
X_00629490* X_00629490::init(int flags) {
    f_0 = &g_0_00629490;
    f_14 = &g_14_00629490;
    f_18 = &g_18_00629490;
    f_20 = &g_20_00629490;
    f_8c = &g_8c_00629490;
    base();
    if (flags & 1) cleanup_00629490(this);
    return this;
}

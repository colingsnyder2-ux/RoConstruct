// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_004db100, g_4_004db100, g_18_004db100, g_1c_004db100, g_94_004db100;
extern "C" void cleanup_004db100(void*);
struct X_004db100 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_004db100* init(int flags);
};
X_004db100* X_004db100::init(int flags) {
    f_0 = &g_0_004db100;
    f_4 = &g_4_004db100;
    f_18 = &g_18_004db100;
    f_1c = &g_1c_004db100;
    f_94 = &g_94_004db100;
    base();
    if (flags & 1) cleanup_004db100(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00714100, g_4_00714100, g_18_00714100, g_1c_00714100, g_80_00714100;
extern "C" void cleanup_00714100(void*);
struct X_00714100 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_00714100* init(int flags);
};
X_00714100* X_00714100::init(int flags) {
    f_0 = &g_0_00714100;
    f_4 = &g_4_00714100;
    f_18 = &g_18_00714100;
    f_1c = &g_1c_00714100;
    f_80 = &g_80_00714100;
    base();
    if (flags & 1) cleanup_00714100(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00815b50, g_4_00815b50, g_18_00815b50, g_1c_00815b50, g_80_00815b50;
extern "C" void cleanup_00815b50(void*);
struct X_00815b50 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_00815b50* init(int flags);
};
X_00815b50* X_00815b50::init(int flags) {
    f_0 = &g_0_00815b50;
    f_4 = &g_4_00815b50;
    f_18 = &g_18_00815b50;
    f_1c = &g_1c_00815b50;
    f_80 = &g_80_00815b50;
    base();
    if (flags & 1) cleanup_00815b50(this);
    return this;
}

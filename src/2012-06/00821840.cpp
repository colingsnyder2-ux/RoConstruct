// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_00821840, g_4_00821840, g_18_00821840, g_1c_00821840, g_80_00821840;
extern "C" void cleanup_00821840(void*);
struct X_00821840 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_00821840* init(int flags);
};
X_00821840* X_00821840::init(int flags) {
    f_0 = &g_0_00821840;
    f_4 = &g_4_00821840;
    f_18 = &g_18_00821840;
    f_1c = &g_1c_00821840;
    f_80 = &g_80_00821840;
    base();
    if (flags & 1) cleanup_00821840(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_007a3f10, g_4_007a3f10, g_18_007a3f10, g_1c_007a3f10, g_80_007a3f10;
extern "C" void cleanup_007a3f10(void*);
struct X_007a3f10 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_007a3f10* init(int flags);
};
X_007a3f10* X_007a3f10::init(int flags) {
    f_0 = &g_0_007a3f10;
    f_4 = &g_4_007a3f10;
    f_18 = &g_18_007a3f10;
    f_1c = &g_1c_007a3f10;
    f_80 = &g_80_007a3f10;
    base();
    if (flags & 1) cleanup_007a3f10(this);
    return this;
}

// from server: 100% by Xemicl
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0, g_4, g_18, g_1c, g_80, g_84;
extern "C" void cleanup_00732ed0(void*);
struct X {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void* f_84;
    void base();
    X* init(int flags);
};
X* X::init(int flags) {
    f_0 = &g_0;
    f_4 = &g_4;
    f_18 = &g_18;
    f_1c = &g_1c;
    f_80 = &g_80;
    f_84 = &g_84;
    base();
    if (flags & 1) cleanup_00732ed0(this);
    return this;
}
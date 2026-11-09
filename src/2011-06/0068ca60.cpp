// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0068ca60, g_4_0068ca60, g_18_0068ca60, g_1c_0068ca60, g_90_0068ca60;
extern "C" void cleanup_0068ca60(void*);
struct X_0068ca60 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_0068ca60* init(int flags);
};
X_0068ca60* X_0068ca60::init(int flags) {
    f_0 = &g_0_0068ca60;
    f_4 = &g_4_0068ca60;
    f_18 = &g_18_0068ca60;
    f_1c = &g_1c_0068ca60;
    f_90 = &g_90_0068ca60;
    base();
    if (flags & 1) cleanup_0068ca60(this);
    return this;
}

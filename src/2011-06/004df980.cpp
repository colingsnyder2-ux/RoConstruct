// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_004df980, g_4_004df980, g_18_004df980, g_1c_004df980, g_90_004df980;
extern "C" void cleanup_004df980(void*);
struct X_004df980 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_004df980* init(int flags);
};
X_004df980* X_004df980::init(int flags) {
    f_0 = &g_0_004df980;
    f_4 = &g_4_004df980;
    f_18 = &g_18_004df980;
    f_1c = &g_1c_004df980;
    f_90 = &g_90_004df980;
    base();
    if (flags & 1) cleanup_004df980(this);
    return this;
}

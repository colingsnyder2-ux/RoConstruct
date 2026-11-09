// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_004af770, g_4_004af770, g_18_004af770, g_1c_004af770, g_94_004af770;
extern "C" void cleanup_004af770(void*);
struct X_004af770 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_004af770* init(int flags);
};
X_004af770* X_004af770::init(int flags) {
    f_0 = &g_0_004af770;
    f_4 = &g_4_004af770;
    f_18 = &g_18_004af770;
    f_1c = &g_1c_004af770;
    f_94 = &g_94_004af770;
    base();
    if (flags & 1) cleanup_004af770(this);
    return this;
}

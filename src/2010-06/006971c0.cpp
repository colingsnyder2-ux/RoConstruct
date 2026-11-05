// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_006971c0, g_4_006971c0, g_18_006971c0, g_1c_006971c0, g_94_006971c0;
extern "C" void cleanup_006971c0(void*);
struct X_006971c0 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_006971c0* init(int flags);
};
X_006971c0* X_006971c0::init(int flags) {
    f_0 = &g_0_006971c0;
    f_4 = &g_4_006971c0;
    f_18 = &g_18_006971c0;
    f_1c = &g_1c_006971c0;
    f_94 = &g_94_006971c0;
    base();
    if (flags & 1) cleanup_006971c0(this);
    return this;
}

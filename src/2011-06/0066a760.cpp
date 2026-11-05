// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0066a760, g_4_0066a760, g_18_0066a760, g_1c_0066a760, g_90_0066a760;
extern "C" void cleanup_0066a760(void*);
struct X_0066a760 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_0066a760* init(int flags);
};
X_0066a760* X_0066a760::init(int flags) {
    f_0 = &g_0_0066a760;
    f_4 = &g_4_0066a760;
    f_18 = &g_18_0066a760;
    f_1c = &g_1c_0066a760;
    f_90 = &g_90_0066a760;
    base();
    if (flags & 1) cleanup_0066a760(this);
    return this;
}

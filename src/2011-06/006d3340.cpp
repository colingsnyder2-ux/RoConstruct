// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_006d3340, g_4_006d3340, g_18_006d3340, g_1c_006d3340, g_90_006d3340;
extern "C" void cleanup_006d3340(void*);
struct X_006d3340 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_006d3340* init(int flags);
};
X_006d3340* X_006d3340::init(int flags) {
    f_0 = &g_0_006d3340;
    f_4 = &g_4_006d3340;
    f_18 = &g_18_006d3340;
    f_1c = &g_1c_006d3340;
    f_90 = &g_90_006d3340;
    base();
    if (flags & 1) cleanup_006d3340(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0062d450, g_4_0062d450, g_18_0062d450, g_1c_0062d450, g_90_0062d450;
extern "C" void cleanup_0062d450(void*);
struct X_0062d450 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_0062d450* init(int flags);
};
X_0062d450* X_0062d450::init(int flags) {
    f_0 = &g_0_0062d450;
    f_4 = &g_4_0062d450;
    f_18 = &g_18_0062d450;
    f_1c = &g_1c_0062d450;
    f_90 = &g_90_0062d450;
    base();
    if (flags & 1) cleanup_0062d450(this);
    return this;
}

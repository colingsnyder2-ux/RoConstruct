// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_004e9560, g_4_004e9560, g_18_004e9560, g_1c_004e9560, g_90_004e9560;
extern "C" void cleanup_004e9560(void*);
struct X_004e9560 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[112];
    void* f_90;
    void base();
    X_004e9560* init(int flags);
};
X_004e9560* X_004e9560::init(int flags) {
    f_0 = &g_0_004e9560;
    f_4 = &g_4_004e9560;
    f_18 = &g_18_004e9560;
    f_1c = &g_1c_004e9560;
    f_90 = &g_90_004e9560;
    base();
    if (flags & 1) cleanup_004e9560(this);
    return this;
}

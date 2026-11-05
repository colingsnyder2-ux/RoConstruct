// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_004d0310, g_14_004d0310, g_18_004d0310, g_20_004d0310, g_8c_004d0310;
extern "C" void cleanup_004d0310(void*);
struct X_004d0310 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_004d0310* init(int flags);
};
X_004d0310* X_004d0310::init(int flags) {
    f_0 = &g_0_004d0310;
    f_14 = &g_14_004d0310;
    f_18 = &g_18_004d0310;
    f_20 = &g_20_004d0310;
    f_8c = &g_8c_004d0310;
    base();
    if (flags & 1) cleanup_004d0310(this);
    return this;
}

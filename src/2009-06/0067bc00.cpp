// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0067bc00, g_14_0067bc00, g_18_0067bc00, g_20_0067bc00, g_8c_0067bc00;
extern "C" void cleanup_0067bc00(void*);
struct X_0067bc00 {
    void* f_0;
    char pad_4[16];
    void* f_14;
    void* f_18;
    char pad_1c[4];
    void* f_20;
    char pad_24[104];
    void* f_8c;
    void base();
    X_0067bc00* init(int flags);
};
X_0067bc00* X_0067bc00::init(int flags) {
    f_0 = &g_0_0067bc00;
    f_14 = &g_14_0067bc00;
    f_18 = &g_18_0067bc00;
    f_20 = &g_20_0067bc00;
    f_8c = &g_8c_0067bc00;
    base();
    if (flags & 1) cleanup_0067bc00(this);
    return this;
}

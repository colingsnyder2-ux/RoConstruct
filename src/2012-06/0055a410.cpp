// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_0055a410, g_4_0055a410, g_18_0055a410, g_1c_0055a410, g_80_0055a410;
extern "C" void cleanup_0055a410(void*);
struct X_0055a410 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[96];
    void* f_80;
    void base();
    X_0055a410* init(int flags);
};
X_0055a410* X_0055a410::init(int flags) {
    f_0 = &g_0_0055a410;
    f_4 = &g_4_0055a410;
    f_18 = &g_18_0055a410;
    f_1c = &g_1c_0055a410;
    f_80 = &g_80_0055a410;
    base();
    if (flags & 1) cleanup_0055a410(this);
    return this;
}

// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern char g_0_005bce90, g_4_005bce90, g_18_005bce90, g_1c_005bce90, g_94_005bce90;
extern "C" void cleanup_005bce90(void*);
struct X_005bce90 {
    void* f_0;
    void* f_4;
    char pad_8[16];
    void* f_18;
    void* f_1c;
    char pad_20[116];
    void* f_94;
    void base();
    X_005bce90* init(int flags);
};
X_005bce90* X_005bce90::init(int flags) {
    f_0 = &g_0_005bce90;
    f_4 = &g_4_005bce90;
    f_18 = &g_18_005bce90;
    f_1c = &g_1c_005bce90;
    f_94 = &g_94_005bce90;
    base();
    if (flags & 1) cleanup_005bce90(this);
    return this;
}

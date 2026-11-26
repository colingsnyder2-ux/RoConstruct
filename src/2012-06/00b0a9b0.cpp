// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
    Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};
struct SettingDescriptor {
    SettingDescriptor(const char* name, const char* category, int offset, Functionality f, int flag);
    ~SettingDescriptor();
    char pad[0x40];
};
static SettingDescriptor desc("ErrorCount", "Results", 0xbc, Functionality(false, false, 0, 0x1f), 0);

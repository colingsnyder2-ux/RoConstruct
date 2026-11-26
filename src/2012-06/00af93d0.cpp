// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Single { int get() const; };
struct Pad { char p[0x1f4]; };
struct B2 { void set(int); };
struct Owner : Pad, B2 { };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality() : a(false), b(false), c(0), d(0x1f) {}
};
struct PropDescriptor {
    typedef int (Single::*Get)() const;
    typedef void (Owner::*Set)(int);
    PropDescriptor(const char* name, const char* category, Get get, Set set, Functionality f, bool flag);
    ~PropDescriptor(); char pad[0x40];
};
static PropDescriptor desc("Image", "Data", &Single::get, &B2::set, Functionality(), false);

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { int b; };
struct Owner : virtual Base { int get() const; };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
    Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};
struct Single { void set(int); };
struct Sig { int v; Sig() : v(0) {} };
struct PropDescriptor {
    typedef int (Owner::*Get)() const;
    typedef void (Single::*Set)(int);
    PropDescriptor(const char* name, const char* category, Get get, Set set, Functionality f, int flag);
    ~PropDescriptor();
    char pad[0x40];
};
static PropDescriptor desc("ControllingHumanoid", "Control", &Owner::get, 0, Functionality(false, false, 0, 0x15), 0);


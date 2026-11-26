// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Single { int get() const; };
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { void set(int); };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
    Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};
struct PropDescriptor {
    typedef int (Single::*Get)() const;
    typedef void (Owner::*Set)(int);
    PropDescriptor(const char* name, const char* category, Get get, Set set, Functionality f, bool flag);
    ~PropDescriptor();
    char pad[0x40];
};
static PropDescriptor desc("Value", "Data", &Single::get, &Owner::set, Functionality(false, false, 0, 0x1f), false);

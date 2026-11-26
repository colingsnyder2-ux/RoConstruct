// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int v; };
struct Base : virtual V { int x; };
struct Pad { char p[0x134]; };
struct Derived : Pad, Base { int get() const; void set(int); };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
    Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};
struct PropDescriptor {
    typedef int (Base::*Get)() const; typedef void (Base::*Set)(int);
    PropDescriptor(const char* name, const char* category, Get get, Set set, Functionality f, int flag);
    ~PropDescriptor(); char pad[0x40];
};
static PropDescriptor desc("Sit", "Control", static_cast<PropDescriptor::Get>(&Derived::get), static_cast<PropDescriptor::Set>(&Derived::set), Functionality(false, false, 0, 0x13), 0);

// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int v; };
struct Base : virtual V { int x; };
struct Pad { char p[0x134]; };
struct Derived : Pad, Base { int get() const; void set(int); };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality() : a(false), b(false), c(0), d(0x1f) {}
};
struct PropDescriptor {
    typedef int (Base::*Get)() const; typedef void (Base::*Set)(int);
    PropDescriptor(const char* name, const char* category, Get get, Set set, Functionality f, bool flag);
    ~PropDescriptor(); char pad[0x40];
};
static PropDescriptor desc("NameOcclusion", "Data", static_cast<PropDescriptor::Get>(&Derived::get), static_cast<PropDescriptor::Set>(&Derived::set), Functionality(), false);


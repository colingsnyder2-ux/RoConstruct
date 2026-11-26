// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Single { int get() const; };
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { void set(int); };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality() : a(false), b(false), c(0), d(0x1f) {}
};
struct PropDescriptor {
    typedef int (Single::*Get)() const;
    typedef void (Owner::*Set)(int);
    PropDescriptor(const char* name, const char* category, Get get, Set set, Functionality f, bool flag);
    ~PropDescriptor();
    char pad[0x40];
};
static PropDescriptor desc("WoodQuality", "Quality", &Single::get, &Owner::set, Functionality(), false);

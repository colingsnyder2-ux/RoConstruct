// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Single { void set(int); };
struct Base1 { int a; }; struct Base2 { int b; };
struct Owner : Base1, Base2 { int get() const; };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality() : a(false), b(false), c(0), d(0x1f) {}
};
struct PropDescriptor {
    typedef int (Owner::*Get)() const;
    typedef void (Single::*Set)(int);
    PropDescriptor(const char* name, const char* category, Get get, Set set, Functionality f, bool flag);
    ~PropDescriptor();
    char pad[0x40];
};
static PropDescriptor desc("CPU", "Profile", &Owner::get, 0, Functionality(), false);

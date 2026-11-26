// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Single { int get() const; };
struct Base { int b; };
struct Owner : virtual Base { void set(int); };
struct Functionality {
    bool a; bool b; int c; int d;
    Functionality(bool a_, bool b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_) {}
    Functionality(const Functionality& o) : a(o.a), b(o.b), c(o.c), d(o.d) {}
};
struct Desc { typedef int (Single::*G)() const; typedef void (Owner::*S)(int);
  Desc(const char* n, const char* c, G g, S s, Functionality fu, int flag); ~Desc(); char pad[0x40]; };
static Desc desc("ClusterGrid", "Data", 0, &Owner::set, Functionality(false,false,0,0x4), 0);
